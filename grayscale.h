#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "bitmapfile.h"

#pragma pack(1) // パッキングの設定
#pragma once

unsigned char rgb_to_gray(unsigned char r, unsigned char g, unsigned char b);
void convert_to_grayscale(const char* input_filename, const char* output_filename);

#endif