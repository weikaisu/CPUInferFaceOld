// Copyright (C) 2018-2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

/* /usr/local/include/opencv2/ */
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
//#include <opencv2/videoio/videoio_c.h>
#include <string>
#include <vector>

class ImageGrabber {
public:
    explicit ImageGrabber(const std::string& fname, int width, int height, int fps);
    bool GrabNext();
    bool Retrieve(cv::Mat& img);
    bool IsOpened() const;
    int GetFrameIndex() const;
    int GetFPS() const;
    int GetWidth() const;
    int GetHeight() const;
    std::string GetVideoPath() const;

private:
    bool is_sequence;
    bool is_opened;
    cv::VideoCapture cap;

    std::vector<std::string> videos;
    std::vector<std::vector<int>> frames;
    int current_video_idx;
    int current_frame_idx;
    int cap_frame_index;

    bool NextVideo();
};
