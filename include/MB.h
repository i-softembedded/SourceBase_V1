#ifndef __MODBUS_RTU_H__
#define __MODBUS_RTU_H__

#include <ModbusRTU.h>

class MODBUS_RTU
{
private:
public:
    bool loadTable;
    bool master;
    QueueHandle_t qUpdateTable;
    struct Config_t
    {
        byte slaveID;
        unsigned long baud;
        HardwareSerial *port;
    } config;
    struct MRead_t
    {
        long startAddress;
        long endAddress;
    } MasterReadReg;
    struct MWrite_t
    {
        long startAddress;
        long endAddress;
    } MasterWriteReg;

    struct SRead_t
    {
        long startAddress;
        long endAddress;
    } SlaveReadReg;
    struct SWrite_t
    {
        long startAddress;
        long endAddress;
    } SlaveWriteReg;
    uint8_t typeData[100];
    void MasterInit(HardwareSerial *port, unsigned long baud);
    void SlaveInit(HardwareSerial *port, unsigned long baud);
    bool read_Multiple_Data(byte ID, uint16_t *value, long startAddress, size_t length);
    bool write_Multiple_Data(byte ID, uint16_t *value, long startAddress, size_t length);
    void loadSetting();
    void writeSetting();
    void update_WebTable();
    void update_WebData_Interval();
};
void TaskModbus(void *pvParameter);

extern MODBUS_RTU modbus;

#endif //__MODBUS_RTU_H__
