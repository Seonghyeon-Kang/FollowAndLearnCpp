#include <iostream>
using namespace std;

class USBDevice
{
private:
    long m_id;

public:
    USBDevice(long id) : m_id(id) {}
    long getID() { return m_id; }
    void plugAndPlay() {
        std::cout << "Plug And Play" << std::endl;
    }
};

class NetworkDevice
{
private:
    long m_id;

public:
    NetworkDevice(long id) : m_id(id) {}
    long getID() { return m_id; }
    void networking() {
        std::cout << "Networking" << std::endl;
    }
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(long usb_id, long net_id)
        : USBDevice(usb_id), NetworkDevice(net_id)
    {}
};

int main()
{
    USBNetworkDevice my_device(314, 6022);

    my_device.networking();
    my_device.plugAndPlay();

    std::cout << my_device.USBDevice::getID() << std::endl;
    std::cout << my_device.NetworkDevice::getID() << std::endl;

    return 0;
}