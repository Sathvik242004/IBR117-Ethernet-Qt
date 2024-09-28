#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

static std::string exec(const char* cmd) {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }

class TestEthernet {
public:
    static bool isConnected() {
        std::string output = exec("sudo ethtool eth0 | grep 'Link detected'");
        return output.find("yes") != std::string::npos;
    }

    static bool isConnected_d() {
        std::cout << "Detecting whether the Ethernet is connected..." << std::endl;
        bool result = isConnected();
        std::cout << "Ethernet connected: " << (result ? "Yes" : "No") << std::endl;
        return result;
    }

    static std::string getEthernetProperties() {
        return exec("sudo ethtool eth0");
    }

    static std::string getEthernetProperties_d() {
        std::cout << "Getting Ethernet properties..." << std::endl;
        std::string output = getEthernetProperties();
        std::cout << output << std::endl;
        return output;
    }

    static bool isInternetAvailable() {
        std::string output = exec("ping -c 1 8.8.8.8");
        return output.find("1 received") != std::string::npos;
    }

    static bool isInternetAvailable_d() {
        std::cout << "Checking internet availability..." << std::endl;
        bool result = isInternetAvailable();
        std::cout << "Internet available: " << (result ? "Yes" : "No") << std::endl;
        return result;
    }

    static std::string getEthernetIp() {
        std::string output = exec("ip addr show eth0 | grep 'inet ' | awk '{print $2}' | cut -d'/' -f1");
        return output.empty() ? "Not Connected" : output;
    }

    static std::string getEthernetIp_d() {
        std::cout << "Getting Ethernet IP address..." << std::endl;
        std::string output = getEthernetIp();
        if (output == "Not Connected") {
            std::cout << "Ethernet is not connected." << std::endl;
        } else {
            std::cout << "Ethernet IP is set to: " << output << std::endl;
        }
        return output;
    }

    static std::string getWlanIp() {
        std::string output = exec("ip addr show wlan0 | grep 'inet ' | awk '{print $2}' | cut -d'/' -f1");
        return output.empty() ? "Not Connected" : output;
    }

    static std::string getWlanIp_d() {
        std::cout << "Getting Wi-Fi IP address..." << std::endl;
        std::string output = getWlanIp();
        if (output == "Not Connected") {
            std::cout << "Wi-Fi is not connected." << std::endl;
        } else {
            std::cout << "Wi-Fi IP is set to: " << output << std::endl;
        }
        return output;
    }

    static void help() {
        std::cout << "This module is for testing the internet/LAN adapter of the IBR117 Board" << std::endl;
        std::cout << "isConnected() checks the status of LAN and returns a bool value" << std::endl;
        std::cout << "isInternetAvailable() checks for the internet status and returns a bool value" << std::endl;
        std::cout << "getEthernetIp() returns the IP address or 'Not Connected'" << std::endl;
        std::cout << "getWlanIp() returns the IP address or 'Not Connected'" << std::endl;
        std::cout << "getEthernetProperties() returns a string containing all the Ethernet properties" << std::endl;
    }
};




class Ethfuncs{
public:
	static std::string getEthernetIp() {
        std::string output = exec("ip addr show eth0 | grep 'inet ' | awk '{print $2}' | cut -d'/' -f1");
        return output.empty() ? "Not Connected" : output;
    }

    static std::string getEthernetIp_d() {
        std::cout << "Getting Ethernet IP address..." << std::endl;
        std::string output = getEthernetIp();
        if (output == "Not Connected") {
            std::cout << "Ethernet is not connected." << std::endl;
        } else {
            std::cout << "Ethernet IP is set to: " << output << std::endl;
        }
        return output;
    }
    
    static std::string StartTCP(std::string ip){
    	std::cout<<"Starting TCP test"<<std::endl;
    	std::cout<<"destination ip is "+ip<<std::endl;
    	std::string cmd="iperf3 -c "+ip+" -i 1 -t 6";
    	std::string output = exec(cmd.c_str());
    	std::cout<<output<<std::endl;
    	return output;
	}
	
	static std::string StartUDP(std::string ip){
    	std::cout<<"Starting UDP test"<<std::endl;
    	std::cout<<"destination ip is "+ip<<std::endl;
    	std::string cmd="iperf3 -c "+ip+" -u -i 1 -b 200M";
    	std::string output = exec(cmd.c_str());
    	std::cout<<output<<std::endl;
    	return output;
	}
    
};