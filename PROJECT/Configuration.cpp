//
// Created by raylyn on 11/20/18.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Configuration.h"

// Default constructor definition
Configuration::Configuration() {
    interval = 0;
    count = 0;
    reportFile = "";
    blk_read = 0;
    blk_read_s = 0;
    kb_read_s = 0;
    blk_write = 0;
    blk_write_s = 0;
    kb_write_s = 0;
}

// Constructor definition
Configuration::Configuration(std::string configFile) {
    std::ifstream inFile;
    inFile.open(configFile);
    if (!inFile) {
        std::cerr << "Error opening file, reverting to default configuration.\n\n";
        inFile.close();
        new (this) Configuration();
    }
    else {
        inFile >> interval >> count >> reportFile >> blk_read >> blk_read_s >> kb_read_s >> blk_write >> blk_write_s >> kb_write_s;
        inFile.close();
    }
}

// GET function definitions
int Configuration::getInterval() {
    return interval;
}

int Configuration::getCount() {
    return count;
}

std::string Configuration::getReportFile() {
    return reportFile;
}

int Configuration::getBlk_read() {
    return blk_read;
}

int Configuration::getBlk_read_s() {
    return blk_read_s;
}

int Configuration::getKb_read_s() {
    return kb_read_s;
}

int Configuration::getBlk_write() {
    return blk_write;
}

int Configuration::getBlk_write_s() {
    return blk_write_s;
}

int Configuration::getKb_write() {
    return kb_write_s;
}

// SET function definitions
void Configuration::setInterval(int _interval) {
    interval = _interval;
}

void Configuration::setCount(int _count) {
    count = _count;
}

void Configuration::setReportFile(std::string _reportFile) {
    reportFile = _reportFile;
}

void Configuration::setBlk_read(int _blk_read) {
    blk_read = _blk_read;
}

void Configuration::setBlk_read_s(int _blk_read_s)  {
    blk_read_s = _blk_read_s;
}

void Configuration::setKb_read_s(int _kb_read_s) {
    kb_read_s = _kb_read_s;
}

void Configuration::setBlk_write(int _blk_write) {
    blk_write = _blk_write;
}

void Configuration::setBlk_write_s(int _blk_write_s) {
    blk_write_s = _blk_write_s;
}

void Configuration::setKb_write(int _kb_write_s) {
    kb_write_s = _kb_write_s;
}

// Save config file
bool Configuration::saveConfig(std::string configFile) {
    std::ofstream outFile;
    outFile.open(configFile);
    if (!outFile) {
        return false;
    }
    outFile << interval << std::endl << count << std::endl << reportFile << std::endl << blk_read << std::endl << blk_read_s << std::endl << kb_read_s << std::endl << blk_write << std::endl << blk_write_s << std::endl << kb_write_s;
    outFile.close();
    return true;
}

void Configuration::printConf() {
    std::cout << "Monitoring time = " << interval << " Seconds, Number of records = " << count << "," << std::endl;
    std::cout << "print_blk_read = " << blk_read << ", print_blk_read/s = " << blk_read_s << ", print_kb_read/s = " << kb_read_s << "," << std::endl;
    std::cout << "print_blk_write = " << blk_write << ", print_blk_write/s = " << blk_write_s << ", print_kb_write/s = " << kb_write_s << "," << std::endl;
    std::cout << "report file name = '" << reportFile << "'\n" << std::endl;
}






