/*
 * Project: PiOmxTextures
 * Author:  Luca Carlon
 * Date:    07.20.2013
 *
 * Copyright (c) 2012, 2013 Luca Carlon. All rights reserved.
 *
 * This file is part of PiOmxTextures.
 *
 * PiOmxTextures is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PiOmxTextures is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PiOmxTextures.  If not, see <http://www.gnu.org/licenses/>.
 */

/*------------------------------------------------------------------------------
|    includes
+-----------------------------------------------------------------------------*/
#include <Qt>

#include <cmath>

#include "omx_playeraudio.h"
#include "lc_logging.h"

using namespace std;

/*------------------------------------------------------------------------------
|    OMX_PlayerAudio::OMX_PlayerAudio
+-----------------------------------------------------------------------------*/
OMX_PlayerAudio::OMX_PlayerAudio() : OMXPlayerAudio()
{
   // Do nothing.
}

/*------------------------------------------------------------------------------
|    OMX_PlayerAudio::~OMX_PlayerAudio
+-----------------------------------------------------------------------------*/
OMX_PlayerAudio::~OMX_PlayerAudio()
{
   // Do nothing.
}

/*------------------------------------------------------------------------------
|    OMX_PlayerAudio::SetMuted
+-----------------------------------------------------------------------------*/
void OMX_PlayerAudio::SetMuted(bool mute)
{
	m_mute = mute;

	if (m_decoder)
		m_decoder->SetMute(m_mute);
}

/*------------------------------------------------------------------------------
|    OMX_PlayerAudio::GetMuted
+-----------------------------------------------------------------------------*/
bool OMX_PlayerAudio::GetMuted()
{
	return m_mute;
}

/*------------------------------------------------------------------------------
|    OMX_PlayerAudio::SetCurrentVolume
+-----------------------------------------------------------------------------*/
/**
 * @brief OMX_PlayerAudio::SetCurrentVolume
 * @param volume
 * @param linear
 */
void OMX_PlayerAudio::SetCurrentVolume(double volume, bool linear)
{
	OMXPlayerAudio::SetVolume((float)volume);
}

/*------------------------------------------------------------------------------
|    OMX_PlayerAudio::GetCurrentVolume
+-----------------------------------------------------------------------------*/
double OMX_PlayerAudio::GetCurrentVolume(bool linear)
{
	return OMXPlayerAudio::GetVolume();
}
