//
// Created by Mehdi Mammadov <mekhti@gmail.com> on 14.03.2022.
//
#include <iostream>
#include <sstream>
#include <memory>

extern "C" {
#include <libavformat/avformat.h>
}

/*
  const int TIMEOUT = 600000;
    int port = 1935;
    bool m_listening = false;

    if (!m_listening) {

        m_listening = true;

        // Format specification: tcp://hostname:port[?options]
        // See: https://www.ffmpeg.org/ffmpeg-protocols.html#tcp

        std::stringstream ss;
        ss << "rtmp://0.0.0.0:" << port;
        const std::string publishingPointURI = ss.str();
        avformat_network_init();
        if (avformat_open_input(&m_stream, publishingPointURI.c_str(), NULL, NULL) != 0) {
            throw Exception(
                    "Unable to buffer stream received from " + publishingPointURI + "");
        }

        m_listening = false;
 */


int main() {
    std::string url = "rtmp://0.0.0.0:1935/app/stream";

    avformat_network_init();
    AVFormatContext *format_context = avformat_alloc_context();
    AVDictionary *options = NULL;
    av_dict_set(&options, "listen", "1", 0);

    avformat_open_input(&format_context, url.c_str(), NULL, &options);

    printf("Format is %s", format_context->iformat->long_name);

    avformat_free_context(format_context);
    av_dict_free(&options);
}
