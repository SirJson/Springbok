// Copyright (C) 2013 Manuel Riecke <m.riecke@mrbeast.org>
//
// TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
// 0. You just DO WHAT THE FUCK YOU WANT TO.

#include "SoundSample.h"
#include "../Dependencies/stb_vorbis.c"
#include "SoundManager.h"
#include <AL/al.h>

SoundSample::SoundSample(const std::string& filename)
{
	// Initialize OpenAL if not done already.
	SoundManager::GetInstance();
	alGenBuffers(1, &BufferIndex);
	
	int error;
	stb_vorbis* file = stb_vorbis_open_filename(const_cast<char*>(filename.c_str()), &error, NULL);
	assert(!error);
	stb_vorbis_info info = stb_vorbis_get_info(file);
	int length = stb_vorbis_stream_length_in_samples(file) * info.channels;
	short* buffer = new short[length];
	stb_vorbis_get_samples_short_interleaved(file, info.channels, buffer, length);
	assert(info.channels > 0 && info.channels < 3);
	if(info.channels == 1)
		alBufferData(BufferIndex, AL_FORMAT_MONO16  , buffer, length*sizeof(short), 44100);
	else if(info.channels == 2)
		alBufferData(BufferIndex, AL_FORMAT_STEREO16, buffer, length*sizeof(short), 44100);
	delete[] buffer;
	assert(!alGetError());
	//free(buffer);
}

SoundSample::~SoundSample()
{
	alDeleteBuffers(1, &BufferIndex);
}