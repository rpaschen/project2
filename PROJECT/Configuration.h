//
// Created by raylyn on 11/20/18.
//

#ifndef PROJECT_CONFIGURATION_H
#define PROJECT_CONFIGURATION_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>


class Configuration {
public:
    // Constructor prototypes

    Configuration();
    Configuration(std::string configFile);

    // GET / SET function prototypes
    int getInterval();
    void setInterval(int _interval);
    int getCount();
    void setCount(int _count);
    std::string getReportFile();
    void setReportFile(std::string _reportFile);
    int getBlk_read();
    void setBlk_read(int _blk_read);
    int getBlk_read_s();
    void setBlk_read_s(int _blk_read_s);
    int getKb_read_s();
    void setKb_read_s(int _kb_read_s);
    int getBlk_write();
    void setBlk_write(int _blk_write);
    int getBlk_write_s();
    void setBlk_write_s(int _blk_write_s);
    int getKb_write();
    void setKb_write(int _kb_write_s);
    bool saveConfig(std::string configFile);
    void printConf();

private:
    // Fields
    int interval; // value
    int count; //value
    std::string reportFile; // name
    int blk_read; // bit
    int blk_read_s; // bit
    int kb_read_s; // bit
    int blk_write; // bit
    int blk_write_s; // bit
    int kb_write_s; // bit

};


#endif //PROJECT_CONFIGURATION_H



//    void reset() {
//
//    }
//
//    void save() {
//
//    }
//
//    void changeConfig() {
//
//    }
//
//    void printConfig() {
//        std::cout << "Monitoring time: " << interval << std::endl;
//        std::cout << "Number of records: " << count << std::endl;
//        std::cout << "print_blk_read: " << print_blk_read << std::endl;
//        std::cout << "print_blk_read/s: " << print_blk_rps << std::endl;
//        std::cout << "print_kb_read/s: " << print_kb_rps << std::endl;
//        std::cout << "print_blk_write: " << print_blk_write << std::endl;
//        std::cout << "print_blk_write/s: " << print_blk_wps << std::endl;
//        std::cout << "print_kb_write/s: " << print_kb_wps << std::endl;
//        std::cout << "report file name: " << reportName << std::endl;
//    }
//
//private:
//    int interval = 1;
//    int count = 10;
//    int print_blk_read = 1;
//    int print_blk_rps = 1;
//    int print_kb_rps = 1;
//    int print_blk_write = 1;
//    int print_blk_wps = 1;
//    int print_kb_wps = 1;
//    std::string reportName = "report.adt";

