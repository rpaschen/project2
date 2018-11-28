//
// Created by raylyn on 11/20/18.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sstream>
#include "Tool.h"
#include "Configuration.h"
#include "Report.h"
#include "CommandLine.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

//using namespace std;

Tool::Tool() {

}

void Tool::welcome() {
    std::cout << "\nauDiskTool, version 1.0.0. Type 'help' to find more about commands.\n" << std::endl;
}

void Tool::help() {
    std::cout << "run - run the monitoring tool." << std::endl;
    std::cout << "set interval [value] - set sampling of records to [value]" << std::endl;
    std::cout << "set count [value] - set the number of records to [value]" << std::endl;
    std::cout << "set report [name] - set the report file name to [name]" << std::endl;
    std::cout << "set blk_read    [0|1] - set print_blk_read to 0 or 1" << std::endl;
    std::cout << "set blk_read/s  [0|1] - set print_blk_read/s to 0 or 1" << std::endl;
    std::cout << "set kb_read/s   [0|1] - set print_kb_read/s to 0 or 1" << std::endl;
    std::cout << "set blk_write   [0|1] - set blk_write to 0 or 1" << std::endl;
    std::cout << "set blk_write/s [0|1] - set blk_write/s to 0 or 1" << std::endl;
    std::cout << "set kb_write    [0|1] - set kb_write to 0 or 1" << std::endl;
    std::cout << "print conf - display all the parameters" << std::endl;
    std::cout << "print report - open and display the report file" << std::endl;
    std::cout << "save - the configuration file audisktool.conf is updated" << std::endl;
    std::cout << "display - exit - exit the tool.\n" << std::endl;
}

void Tool::run() {

    Tool t;
    t.welcome();
    std::string configFile = "audisktool.conf";
    std::string command;
    int position;
    std::string tempCmd;
    std::string tempCmd2;
    std::string tempCmd3;
    int value;
    Configuration conf(configFile);
    CommandLine cmd;
    Report rep(conf.getReportFile());

    while (true) {
        std::cout << ">";
        getline(std::cin, command);

        // help command
        if(command == "help") {
            t.help();
        }

        else if(command == "run") {

            conf.printConf();
            std::cout << "Please wait...\n" << std::endl;
            for (int i = 0; i <conf.getCount(); i++) {
                cmd.getData(rep);
                sleep(conf.getInterval());
            }
            rep.writeReport(conf);
            std::cout << "A file '" << conf.getReportFile() << "' is updated.\n";
        }

        else if(command == "print conf") {
            conf.printConf();
        }

        else if(command == "print report") {
            if (rep.records.empty()) {
                std::cout << "No record found in '" << rep.reportFile << "'\n" << std::endl;
            }
            else {
                rep.printReport(conf);
            }
        }

        else if (command == "save") {
            Configuration testConfig(configFile);

            if (conf.getInterval() == testConfig.getInterval() && conf.getCount() == testConfig.getCount()
                && conf.getBlk_read() == testConfig.getBlk_read() && conf.getBlk_read_s() == testConfig.getBlk_read_s()
                && conf.getKb_read_s() == testConfig.getKb_read_s() && conf.getBlk_write() == testConfig.getBlk_write()
                && conf.getBlk_write_s() == testConfig.getBlk_write_s() && conf.getKb_write() == testConfig.getKb_write()) {

                std::cout << "audisktool.conf has not been updated. There is no need to save the file.\n" << std::endl;
            }
            else {
                conf.saveConfig(configFile);
                std::cout << "file audisktool.conf has been updated.\n" << std::endl;
            }
        }
        else if (command == "display") {
            std::cout << "Exiting the tool...\n" << std::endl;
            break;
        }

            // set bits commands:
        else if (command == "set blk_read 0") {
            if (conf.getBlk_read() == 0) {
                std::cout << "Print_blk_read was 0; the parameter remains unchanged to 0.\n" << std::endl;
            }
            else {
                conf.setBlk_read(0);
                std::cout << "Print_blk_read has been changed to 0.\n" << std::endl;
            }
        }
        else if (command == "set blk_read 1") {
            if (conf.getBlk_read() == 1) {
                std::cout << "Print_blk_read was 1; the parameter remains unchanged to 1.\n" << std::endl;
            }
            else {
                conf.setBlk_read(1);
                std::cout << "Print_blk_read has been changed to 1.\n" << std::endl;
            }
        }
        else if (command == "set blk_read/s 0") {
            if (conf.getBlk_read_s() == 0) {
                std::cout << "Print_blk_read/s was 0; the parameter remains unchanged to 0.\n" << std::endl;
            }
            else {
                conf.setBlk_read_s(0);
                std::cout << "Print_blk_read/s has been changed to 0.\n" << std::endl;
            }
        }
        else if (command == "set blk_read/s 1") {
            if (conf.getBlk_read_s() == 1) {
                std::cout << "Print_blk_read/s was 1; the parameter remains unchanged to 1.\n" << std::endl;
            }
            else {
                conf.setBlk_read_s(1);
                std::cout << "Print_blk_read/s has been changed to 1.\n" << std::endl;
            }
        }
        else if (command == "set kb_read/s 0") {
            if (conf.getKb_read_s() == 0) {
                std::cout << "Print_kb_read/s was 0; the parameter remains unchanged to 0.\n" << std::endl;
            }
            else {
                conf.setKb_read_s(0);
                std::cout << "Print_kb_read/s has been changed to 0.\n" << std::endl;
            }
        }
        else if (command == "set kb_read/s 1") {
            if (conf.getKb_read_s() == 1) {
                std::cout << "Print_kb_read/s was 1; the parameter remains unchanged to 1.\n" << std::endl;
            }
            else {
                conf.setKb_read_s(1);
                std::cout << "Print_kb_read/s has been changed to 1.\n" << std::endl;
            }
        }
        else if (command == "set blk_write 0") {
            if (conf.getBlk_write() == 0) {
                std::cout << "Print_blk_write was 0; the parameter remains unchanged to 0.\n" << std::endl;
            }
            else {
                conf.setBlk_write(0);
                std::cout << "Print_blk_write has been changed to 0.\n" << std::endl;
            }
        }
        else if (command == "set blk_write 1") {
            if (conf.getBlk_write() == 1) {
                std::cout << "Print_blk_write was 1; the parameter remains unchanged to 1.\n" << std::endl;
            }
            else {
                conf.setBlk_write(1);
                std::cout << "Print_blk_write has been changed to 1.\n" << std::endl;
            }
        }
        else if (command == "set blk_write/s 0") {
            if (conf.getBlk_write_s() == 0) {
                std::cout << "Print_blk_write/s was 0; the parameter remains unchanged to 0.\n" << std::endl;
            }
            else {
                conf.setBlk_write_s(0);
                std::cout << "Print_blk_write/s has been changed to 0.\n" << std::endl;
            }
        }
        else if (command == "set blk_write/s 1") {
            if (conf.getBlk_write_s() == 1) {
                std::cout << "Print_blk_write/s was 1; the parameter remains unchanged to 1.\n" << std::endl;
            }
            else {
                conf.setBlk_write_s(1);
                std::cout << "Print_blk_write/s has been changed to 1.\n" << std::endl;
            }
        }
        else if (command == "set kb_write 0") {
            if (conf.getKb_write() == 0) {
                std::cout << "Print_kb_write was 1; the parameter remains unchanged to 0.\n" << std::endl;
            }
            else {
                conf.setKb_write(0);
                std::cout << "Print_kb_write has been changed to 0.\n" << std::endl;
            }
        }
        else if (command == "set kb_write 1") {
            if (conf.getKb_write() == 1) {
                std::cout << "Print_kb_write was 1; the parameter remains unchanged to 1.\n" << std::endl;
            }
            else {
                conf.setKb_write(1);
                std::cout << "Print_kb_write has been changed to 1.\n" << std::endl;
            }
        }

            // invalid commands:
        else {
            position = command.find(" ");
            tempCmd = command.substr(0, position);
            command = command.substr(position + 1);
            position = command.find(" ");
            tempCmd2 = command.substr(0, position);
            tempCmd3 = command.substr(position + 1);

            if(tempCmd == "set") {
                if(tempCmd2 == "interval") {
                    std::istringstream value_buffer(tempCmd3);
                    value_buffer >> value;

                    if(conf.getInterval() == value) {
                        std::cout << "Interval was " << conf.getInterval() << "; the parameter remains unchanged to " << conf.getInterval() << ".\n" << std::endl;
                    }
                    else {
                        conf.setInterval(value);
                        std::cout << "Interval has been changed to " << value << ".\n" << std::endl;
                    }
                }

                else if(tempCmd2 == "count") {
                    std::istringstream value_buffer(tempCmd3);
                    value_buffer >> value;

                    if(conf.getCount() == value) {
                        std::cout << "Count was " << conf.getCount() << "; the parameter remains unchanged to " << conf.getCount() << ".\n" << std::endl;
                    }
                    else {
                        conf.setCount(value);
                        std::cout << "Count has been changed to " << value << ".\n" << std::endl;
                    }
                }

                else if(tempCmd2 == "report") {
                    if(conf.getReportFile() == tempCmd3) {
                        std::cout << "Report file name was " << conf.getReportFile() << "; the parameter remains unchanged to " << conf.getReportFile() << ".\n" << std::endl;
                    }
                    else {
                        std::cout << "The report file name is changed from ‘" << conf.getReportFile() << "' to '" << tempCmd3 << "'.\n";
                        std::cout << "You can now type ‘run’ to generate new records to be saved in" << std::endl;
                        std::cout << "'" << tempCmd3 << "'" << std::endl;
                        std::cout << "Note: '" << conf.getReportFile() << "' will not be deleted by audisktool." << std::endl;
                        conf.setReportFile(tempCmd3);
                        rep.reportFile = tempCmd3;
                    }
                }
            }
        }

    }
}


#pragma clang diagnostic pop