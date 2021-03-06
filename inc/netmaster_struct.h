#ifndef NETMASTER_STRUCT_H
#define NETMASTER_STRUCT_H

/*
 * netmaster_struct.h
 *
 * AUTOGENERATED FILE! ONLY EDIT IF YOU ARE A MACHINE!
 *
 * Created on: 2020-06-01 15:18:35.339516
 * Author: Dephy, Inc.
 *
 */

#include "NetMaster_device_spec.h"
#include <stdio.h> 
#include <time.h> 
#include <string.h> 
#include <stdint.h> 

#define NETMASTER_SYSTEM_TIME_POS 72
#define NETMASTER_STRUCT_DEVICE_FIELD_COUNT 73
#define NETMASTER_LABEL_MAX_CHAR_LENGTH 11

//This is The Device fields*10 + deviceField+1. Ten is the max string length of 2^32 in decimal separated from commas
#define NETMASTER_DATA_STRING_LENGTH 804

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(1)

struct NetMasterState
{
	int netmaster;
	int id;
	int state_time;
	int genvar_0;
	int genvar_1;
	int genvar_2;
	int genvar_3;
	int status;
	int a_accelx;
	int a_accely;
	int a_accelz;
	int a_gyrox;
	int a_gyroy;
	int a_gyroz;
	int a_pressure;
	int a_status;
	int b_accelx;
	int b_accely;
	int b_accelz;
	int b_gyrox;
	int b_gyroy;
	int b_gyroz;
	int b_pressure;
	int b_status;
	int c_accelx;
	int c_accely;
	int c_accelz;
	int c_gyrox;
	int c_gyroy;
	int c_gyroz;
	int c_pressure;
	int c_status;
	int d_accelx;
	int d_accely;
	int d_accelz;
	int d_gyrox;
	int d_gyroy;
	int d_gyroz;
	int d_pressure;
	int d_status;
	int e_accelx;
	int e_accely;
	int e_accelz;
	int e_gyrox;
	int e_gyroy;
	int e_gyroz;
	int e_pressure;
	int e_status;
	int f_accelx;
	int f_accely;
	int f_accelz;
	int f_gyrox;
	int f_gyroy;
	int f_gyroz;
	int f_pressure;
	int f_status;
	int g_accelx;
	int g_accely;
	int g_accelz;
	int g_gyrox;
	int g_gyroy;
	int g_gyroz;
	int g_pressure;
	int g_status;
	int h_accelx;
	int h_accely;
	int h_accelz;
	int h_gyrox;
	int h_gyroy;
	int h_gyroz;
	int h_pressure;
	int h_status;
	//the system time
	int systemTime;
	uint32_t deviceData[NETMASTER_STRUCT_DEVICE_FIELD_COUNT];
};

#pragma pack()

/// \brief Assigns the data in the buffer to the correct struct parameters
///
///@param NetMaster is the struct with the data to be set
///
///@param _deviceStateBuffer is the buffer containing the data to be assigned to the struct
///
///@param systemStartTime the time the system started. If unknown, use 0.
///
void NetMasterSetData(struct NetMasterState *netmaster, uint32_t _deviceStateBuffer[], int systemStartTime);

/// \brief takes all data and places it into single, comma separated string
///
///@param NetMaster is the struct with the data to be placed in the string
///
///@param dataString is where the new string wll be placed 
///
void NetMasterDataToString(struct NetMasterState *netmaster, char dataString[NETMASTER_DATA_STRING_LENGTH]);

/// \brief retrieves the string equivalent of all parameter names
///
///@param labels is the array of labels containing the parameter names
///
void NetMasterGetLabels(char labels[NETMASTER_STRUCT_DEVICE_FIELD_COUNT][NETMASTER_LABEL_MAX_CHAR_LENGTH]);

/// \brief retrieves the string equivalent of parameter names starting with state time.  Parameters 
/// prior to state time, such as id,  are not included. 
///
///@param labels is the array of labels containing the parameter names
///
int NetMasterGetLabelsForLog(char labels[NETMASTER_STRUCT_DEVICE_FIELD_COUNT][NETMASTER_LABEL_MAX_CHAR_LENGTH]);

#ifdef __cplusplus
}//extern "C"
#endif

#endif ////ACTPACK_STRUCT_H
