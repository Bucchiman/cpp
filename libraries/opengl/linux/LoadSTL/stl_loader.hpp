#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

struct Vec3 {
    float x, y, z;
};

struct Triangle {
    Vec3 normal;
    Vec3 vertices[3];
};

bool loadBinarySTL(const std::string& filename, std::vector<Triangle>& triangles) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open STL file: " << filename << std::endl;
        return false;
    }

    char header[80];
    file.read(header, 80);
    uint32_t triangleCount;
    file.read(reinterpret_cast<char*>(&triangleCount), 4);

    triangles.resize(triangleCount);
    for (uint32_t i = 0; i < triangleCount; ++i) {
        Triangle& tri = triangles[i];
        file.read(reinterpret_cast<char*>(&tri.normal), sizeof(Vec3));
        for (int j = 0; j < 3; ++j) {
            file.read(reinterpret_cast<char*>(&tri.vertices[j]), sizeof(Vec3));
        }
        uint16_t attr;
        file.read(reinterpret_cast<char*>(&attr), 2);  // attribute byte count (ignored)
    }

    return true;
}
