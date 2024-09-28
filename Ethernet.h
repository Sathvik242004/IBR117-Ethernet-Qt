#ifndef TEST_ETHERNET_H
#define TEST_ETHERNET_H

#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <cstring>
#include <array>
#include <sstream>
#include <thread>
#include <future>
#include <chrono>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <functional>

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

static std::string exect(const char* cmd, int timeout_seconds) {
        std::promise<std::string> promise;
        std::future<std::string> future = promise.get_future();

        std::thread([cmd, &promise]() {
            promise.set_value(exec(cmd));
        }).detach();

        if (future.wait_for(std::chrono::seconds(timeout_seconds)) == std::future_status::timeout) {
            // Timeout
            return "Command timed out";
        } else {
            return future.get();
        }
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


class Ethfuncs {
public:
    	static std::string setDeviceEthIp(const std::string& ip){
	std::string cmd="ifconfig eth0 "+ip;
    	std::string output=exec(cmd.c_str());
		return ("ip is set to "+ip);
}
	static std::string setDeviceWifiIp(const std::string& ip){
	std::string cmd="ifconfig wifi0 "+ip;
	std::string output=exec(cmd.c_str());
		return ("ip is set to "+ip);
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
    
    static std::string StartTCP(const std::string& ip) {
        std::cout << "Starting TCP test" << std::endl;
        std::cout << "Destination IP is " + ip << std::endl;

        std::string cmd = "iperf3 -c " + ip + " -i 1 -t 15"; // Run the test for 15 seconds
        std::string output = exect(cmd.c_str(),20);

        // Check if the output contains the success indicators
        bool success = output.find("sender") != std::string::npos && output.find("receiver") != std::string::npos;
        
        if (success) {
            return "TCP test successful";
        } else {
            return "TCP test failed";
        }
    }
    
    static std::string StartUDP(const std::string& ip) {
        std::cout << "Starting UDP test" << std::endl;
        std::cout << "Destination IP is " + ip << std::endl;

        std::string cmd = "iperf3 -c " + ip + " -u -i 1 -b 200M"; // Run the test with UDP
        std::string output = exect(cmd.c_str(),20);

        // Check if the output contains the success indicators
        bool success = output.find("connected") != std::string::npos;
        
        if (success) {
            return "UDP test successful";
        } else {
            return "UDP test failed";
        }
    }
    static std::string sendMessage(const std::string& ip,const std::string& message){
    	std::cout<<"Sending message";
	std::string cmd="echo "+message+" | nc "+ip+" 5000";
    	std::string open=exec(cmd.c_str());
	return open;	
	}
	
	static std::string receiveMessage(const std::string& ip) {
    std::cout<<"Receiving messaeg";
	std::string cmd="echo "" | nc "+ip+" 5000";
    	std::string open=exec(cmd.c_str());
	return open;
}

};

class senrec {
public:
    using MessageCallback = std::function<void(const std::string&)>;

    senrec(const std::string& ip, int port) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            throw std::runtime_error("Socket creation failed.");
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        if (inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr) <= 0) {
            close(sock);
            throw std::runtime_error("Invalid address/Address not supported.");
        }

        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            close(sock);
            throw std::runtime_error("Connection failed.");
        }

        listening = true;
    }

    ~senrec() {
        stopListening();
        close(sock);
    }

    void sendMessagetcp(const std::string& message) {
        if (send(sock, message.c_str(), message.size(), 0) < 0) {
            throw std::runtime_error("Failed to send TCP message.");
        }
    }

    void receiveMessage(MessageCallback callback) {
        listenThread = std::thread([this, callback]() {
            while (listening) {
                std::array<char, 1024> buffer;
                ssize_t bytes_received = recv(sock, buffer.data(), buffer.size(), 0);
                if (bytes_received > 0) {
                    std::string message(buffer.data(), bytes_received);
                    callback(message);
                } else if (bytes_received < 0) {
                    throw std::runtime_error("Failed to receive message.");
                }
            }
        });
    }

    void sendMessageudp(const std::string& message) {
        int udp_sock = socket(AF_INET, SOCK_DGRAM, 0); // Use a separate UDP socket
        if (udp_sock < 0) {
            throw std::runtime_error("Socket creation failed.");
        }
        if (sendto(udp_sock, message.c_str(), message.size(), 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            close(udp_sock);
            throw std::runtime_error("Failed to send UDP message.");
        }
        close(udp_sock);
    }

    void stopListening() {
        listening = false;
        if (listenThread.joinable()) {
            listenThread.join();
        }
    }

public:
    int sock;
    sockaddr_in server_addr;
    bool listening;
    std::thread listenThread;
};


#endif
