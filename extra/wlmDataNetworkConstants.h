/** ***************************************************************************************************
* @file wlmDataNetworkConstants.h
* @copyright HighFinesse GmbH.
* @author Lovas Szilard <lovas@highfinesse.de>
* @date 2021.12.09
* @version 0.6
* @brief Networked wlmData API library constants
*
* Changelog:
* ----------
* 2021.02.17 v0.1 
* - Initial release
* 2021.03.02 v0.2 
* - API level 7.254.xx related functions are added
* 2021.09.02 v0.3 
* - cCallbackServer constant added
* 2021.09.16 v0.4 
* - API level 7.263.xx related functions are added
* 2021.11.10 v0.5 
* - manual network control related constants are added
* 2021.12.09 v0.6 
* - manual network control related constants simplifed
*
* Networked library specific usage of long Instantiate(long RFC, long Mode, long *P1, long P2) function:
* ======================================================================================================
* Network connection state control:
* ---------------------------------
*   'RFC' = cInstNetworkControl
*   'Mode' = cSetConnectState 
*       'P1': (eConnState_t *)P1 (input)
        'P2': don't care (can be set to 0) 
*   'Mode' = cGetConnectState
*       'P1': (eConnState_t *)P1 (output)
        'P2': don't care (can be set to 0)
*   return value: 1: success, 0: otherwise

* Network connection parameter control:
* -------------------------------------
*   'RFC' = cInstNetworkControl
*   'Mode' = cSetParameter
*       'P1': (const char *)P1: ini file entry in "name = value" format (input)
*       'P2': don't care (can be set to 0)
*   'Mode' = cGetParameter
*       'P1': (char *)P1 ini file variable name (input) / value (output)
*       'P2': don't care (can be set to 0)
*
* Example:
* --------
*   // connecting to server: "lab_pc1.local" using IPv6, setget port: 7000, callback port 7001 
*   Instantiate(cInstNetworkControl, cSetParameter, (LONG_PTR)"address = lab_pc1.local", 0);
*   Instantiate(cInstNetworkControl, cSetParameter, (LONG_PTR)"version = 6", 0);
*   Instantiate(cInstNetworkControl, cSetParameter, (LONG_PTR)"port = 7000", 0);
*   Instantiate(cInstNetworkControl, cSetParameter, (LONG_PTR)"port2 =7001", 0);
* 
*   // Initiating network connection
*   eConnState_t xConnect = eNET_CONNECTED;
*   Instantiate(cInstNetworkControl, cSetConnectState, (LONG_PTR)&xConnect, 0);
*
*   // Getting connection parameter
*   char cBuffer[defBUF_LEN] = "address";
*   Instantiate(cInstNetworkControl, cGetParameter, (LONG_PTR)cBuffer, 0);
*   printf("Server address: %s\r\n", cBuffer);
*   
*/

#pragma once
/* Server access return (FAccess) constants */
const int16_t cServerAccessGranted = 1;
const int16_t cServerAccessRejected = 2;

/* Instantiate() function network library specific parameters */

/* Log and error callback control: 'RFC' = cInstNotification */
/* ========================================================= */
/* Log and error 'Mode' constants: */
const int32_t cNotifyInstallLogEvent = 1000;
const int32_t cNotifyInstallErrorEvent = 1001;
const int32_t cNotifyRemoveLogEvent = 1002;
const int32_t cNotifyRemoveErrorEvent = 1003;

/* Network connection control 'RFC' = cInstNetworkControl */
/* ====================================================== */
#ifndef cInstNetworkControl
const int32_t cInstNetworkControl = 6;
#endif
/* Network connection control 'Mode' constants */
const int32_t cSetConnectState = 1000;
const int32_t cGetConnectState = 1001;
const int32_t cSetParameter = 1002;
const int32_t cGetParameter = 1003;

/* Network connection states */
enum eConnState_t:uint32_t { eNET_DISCONNECTED = 0,  eNET_CONNECTED };

/* Error Source IDs others: */
const int32_t cCallbackServer = -1;

/* Error Source IDs API functions */
/* Functions for general usage */
const int32_t cInstantiate = 0;

const int32_t cCallbackProc = 1;
const int32_t cCallbackProcEx = 2;

const int32_t cWaitForWLMEvent = 3;
const int32_t cWaitForWLMEventEx = 4;
const int32_t cWaitForNextWLMEvent = 5;
const int32_t cWaitForNextWLMEventEx = 6;
const int32_t cClearWLMEvents = 7;

const int32_t cControlWLM = 8;
const int32_t cControlWLMEx = 9;
const int32_t cSynchroniseWLM = 10;
const int32_t cSetMeasurementDelayMethod = 11;
const int32_t cSetWLMPriority = 12;
const int32_t cPresetWLMIndex = 13;

const int32_t cGetWLMVersion = 14;
const int32_t cGetWLMIndex = 15;
const int32_t cGetWLMCount = 16;

/* General Get... & Set...-functions */
const int32_t cGetWavelength = 17;
const int32_t cGetWavelength2 = 18;
const int32_t cGetWavelengthNum = 19;
const int32_t cGetCalWavelength = 20;
const int32_t cGetCalibrationEffect = 21;
const int32_t cGetFrequency = 22;
const int32_t cGetFrequency2 = 23;
const int32_t cGetFrequencyNum = 24;
const int32_t cGetLinewidth = 25;
const int32_t cGetLinewidthNum = 26;
const int32_t cGetDistance = 27;
const int32_t cGetAnalogIn = 28;
const int32_t cGetTemperature = 29;
const int32_t cSetTemperature = 30;
const int32_t cGetPressure = 31;
const int32_t cSetPressure = 32;
const int32_t cGetExternalInput = 33;
const int32_t cSetExternalInput = 34;
const int32_t cGetExtraSetting = 35;
const int32_t cSetExtraSetting = 36;

const int32_t cGetExposure = 37;
const int32_t cSetExposure = 38;
const int32_t cGetExposure2 = 39;
const int32_t cSetExposure2 = 40;
const int32_t cGetExposureNum = 41;
const int32_t cSetExposureNum = 42;
const int32_t cGetExposureNumEx = 43;
const int32_t cSetExposureNumEx = 44;
const int32_t cGetExposureMode = 45;
const int32_t cSetExposureMode = 46;
const int32_t cGetExposureModeNum = 47;
const int32_t cSetExposureModeNum = 48;
const int32_t cGetExposureRange = 49;
const int32_t cGetAutoExposureSetting = 50;
const int32_t cSetAutoExposureSetting = 51;

const int32_t cGetResultMode = 52;
const int32_t cSetResultMode = 53;
const int32_t cGetRange = 54;
const int32_t cSetRange = 55;
const int32_t cGetPulseMode = 56;
const int32_t cSetPulseMode = 57;
const int32_t cGetPulseDelay = 58;
const int32_t cSetPulseDelay = 59;
const int32_t cGetWideMode = 60;
const int32_t cSetWideMode = 61;

const int32_t cGetDisplayMode = 62;
const int32_t cSetDisplayMode = 63;
const int32_t cGetFastMode = 64;
const int32_t cSetFastMode = 65;

const int32_t cGetLinewidthMode = 66;
const int32_t cSetLinewidthMode = 67;

const int32_t cGetDistanceMode = 68;
const int32_t cSetDistanceMode = 69;

const int32_t cGetSwitcherMode = 70;
const int32_t cSetSwitcherMode = 71;
const int32_t cGetSwitcherChannel = 72;
const int32_t cSetSwitcherChannel = 73;
const int32_t cGetSwitcherSignalStates = 74;
const int32_t cSetSwitcherSignalStates = 75;
const int32_t cSetSwitcherSignal = 76;

const int32_t cGetAutoCalMode = 77;
const int32_t cSetAutoCalMode = 78;
const int32_t cGetAutoCalSetting = 79;
const int32_t cSetAutoCalSetting = 80;

const int32_t cGetActiveChannel = 81;
const int32_t cSetActiveChannel = 82;
const int32_t cGetChannelsCount = 83;

const int32_t cGetOperationState = 84;
const int32_t cOperation = 85;
const int32_t cSetOperationFile = 86;
const int32_t cCalibration = 87;
const int32_t cRaiseMeasurementEvent = 88;
const int32_t cTriggerMeasurement = 89;
const int32_t cGetTriggerState = 90;
const int32_t cGetInterval = 91;
const int32_t cSetInterval = 92;
const int32_t cGetIntervalMode = 93;
const int32_t cSetIntervalMode = 94;
const int32_t cGetBackground = 95;
const int32_t cSetBackground = 96;
const int32_t cGetAveragingSettingNum = 97;
const int32_t cSetAveragingSettingNum = 98;

const int32_t cGetLinkState = 99;
const int32_t cSetLinkState = 100;
const int32_t cLinkSettingsDlg = 101;

const int32_t cGetPatternItemSize = 102;
const int32_t cGetPatternItemCount = 103;
const int32_t cGetPattern = 104;
const int32_t cGetPatternNum = 105;
const int32_t cGetPatternData = 106;
const int32_t cGetPatternDataNum = 107;
const int32_t cSetPattern = 108;
const int32_t cSetPatternData = 109;

const int32_t cGetAnalysisMode = 110;
const int32_t cSetAnalysisMode = 111;
const int32_t cGetAnalysisItemSize = 112;
const int32_t cGetAnalysisItemCount = 113;
const int32_t cGetAnalysis = 114;
const int32_t cGetAnalysisData = 115;
const int32_t cSetAnalysis = 116;

const int32_t cGetMinPeak = 117;
const int32_t cGetMinPeak2 = 118;
const int32_t cGetMaxPeak = 119;
const int32_t cGetMaxPeak2 = 120;
const int32_t cGetAvgPeak = 121;
const int32_t cGetAvgPeak2 = 122;
const int32_t cSetAvgPeak = 123;

const int32_t cGetAmplitudeNum = 124;
const int32_t cGetIntensityNum = 125;
const int32_t cGetPowerNum = 126;

const int32_t cGetDelay = 127;
const int32_t cSetDelay = 128;
const int32_t cGetShift = 129;
const int32_t cSetShift = 130;
const int32_t cGetShift2 = 131;
const int32_t cSetShift2 = 132;

/* Deviation and PID-functions */
const int32_t cGetDeviationMode = 133;
const int32_t cSetDeviationMode = 134;
const int32_t cGetDeviationReference = 135;
const int32_t cSetDeviationReference = 136;
const int32_t cGetDeviationSensitivity = 137;
const int32_t cSetDeviationSensitivity = 138;
const int32_t cGetDeviationSignal = 139;
const int32_t cGetDeviationSignalNum = 140;
const int32_t cSetDeviationSignal = 141;
const int32_t cSetDeviationSignalNum = 142;
const int32_t cRaiseDeviationSignal = 143;

const int32_t cGetPIDCourse = 144;
const int32_t cSetPIDCourse = 145;
const int32_t cGetPIDCourseNum = 146;
const int32_t cSetPIDCourseNum = 147;
const int32_t cGetPIDSetting = 148;
const int32_t cSetPIDSetting = 149;
const int32_t cGetLaserControlSetting = 150;
const int32_t cSetLaserControlSetting = 151;
const int32_t cClearPIDHistory = 152;

/* Other...-functions */
const int32_t cConvertUnit = 153;
const int32_t cConvertDeltaUnit = 154;

/* Obsolete...-functions */
const int32_t cGetReduced = 155;
const int32_t cSetReduced = 156;
const int32_t cGetScale = 157;
const int32_t cSetScale = 158;

/* FID range 159-163 reserved for internal usage */

const int32_t cGetAirParameters = 164;
const int32_t cSetAirParameters = 165;
const int32_t cGetExposureRangeEx = 166;

/* API level 7.254.xx level function IDs */
//const int32_t cGetOptionInfo = 167;			// Obsolote function signature, compared to 7.263.xx
const int32_t cGetInternalTriggerRate = 168;
const int32_t cSetInternalTriggerRate = 169;
const int32_t cGetGain = 170;
const int32_t cSetGain = 171;
const int32_t cGetMultimodeInfo = 172;

/* API level 7.263.xx level function IDs */
const int32_t cGetWLMInfo = 173;
const int32_t cGetDeviceInfo = 174;
const int32_t cGetOptionInfo = 175;				// Updated function signature, compared to 7.254.xx
const int32_t cGetResultInfo = 176;
const int32_t cGetPulseIntegration = 177;
const int32_t cSetPulseIntegration = 178;
const int32_t cPowerCalibration = 179;	// (set function)