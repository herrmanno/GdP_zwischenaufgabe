#pragma once

#include <string>

/**
 * Reads a file's content into a string representation
 * 
 * Does not handle illegal file paths
 * 
 * @param file path to the file to read
 * @returns the file's contents as string
 */
std::string getFileContent(const std::string& file);