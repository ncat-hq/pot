/*
 * Project: PiOmxTextures
 * Author:  Luca Carlon
 * Date:    04.11.2015
 *
 * Copyright (c) 2015 Luca Carlon. All rights reserved.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PiOmxTextures. If not, see <http://www.gnu.org/licenses/>.
 */

import QtQuick 2.0
import QtMultimedia 5.0

Rectangle {
	anchors.fill: parent

	Video {
		id: myVideo
		anchors.fill: parent
		muted: false
		//autoPlay:true
		//source: "file:///home/pi/big_buck_bunny_1080p_h264.mov"

		onPlaybackStateChanged: {
			if (playbackState === MediaPlayer.PlayingState)
				myTimer.start();
		}
	}

	Timer {
		property int loops: 0

		id: myTimer
		interval: 10000
		repeat: true
		running: false
		triggeredOnStart: false
		onTriggered: {
			loops++;
			var index = loops%5;
			var duration = myVideo.duration;
			var position = index/5*duration;

			myVideo.seek(position);
			logger.info("Seeked " + loops + " times. Seeked to " + position + ".");
		}
	}

	Item {
		id: mediaOutput
		objectName: "mediaOutput"

		function showUrlMedia(uri) {
			myVideo.source = uri;
			myVideo.play();
		}
	}
}
