/*
 *
 *    Copyright (c) 2020-2022 Project CHIP Authors
 *    Copyright (c) 2018 Nest Labs, Inc.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Platform-specific configuration overrides for the Chip Device Layer
 *          on the ESP32.
 */

#pragma once

// ==================== Platform Adaptations ====================

#define CHIP_DEVICE_CONFIG_LWIP_WIFI_STATION_IF_NAME "st"

#define CHIP_DEVICE_CONFIG_ESP32_BLE_ERROR_MIN 0xB00000
// ==================== Kconfig Overrides ====================

// The following values are configured via the ESP-IDF Kconfig mechanism.

#define CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE CONFIG_CHIP_TASK_STACK_SIZE
#define CHIP_DEVICE_CONFIG_CHIP_TASK_PRIORITY CONFIG_CHIP_TASK_PRIORITY
#define CHIP_DEVICE_CONFIG_MAX_EVENT_QUEUE_SIZE CONFIG_MAX_EVENT_QUEUE_SIZE
#ifndef CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID
#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID CONFIG_DEVICE_VENDOR_ID
#endif /* CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID */
#ifndef CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID CONFIG_DEVICE_PRODUCT_ID
#define CHIP_DEVICE_CONFIG_DEVICE_TYPE CONFIG_DEVICE_TYPE
#define CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION CONFIG_DEFAULT_DEVICE_HARDWARE_VERSION

#endif /* CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID */

#define CHIP_DEVICE_CONFIG_ENABLE_THREAD CONFIG_OPENTHREAD_ENABLED
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_SRP_CLIENT CONFIG_OPENTHREAD_SRP_CLIENT
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_DNS_CLIENT CONFIG_OPENTHREAD_SRP_CLIENT

#if CONFIG_IDF_TARGET_ESP32H2
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI 0
#else
#define CHIP_DEVICE_CONFIG_WIFI_STATION_RECONNECT_INTERVAL CONFIG_WIFI_STATION_RECONNECT_INTERVAL
#define CHIP_DEVICE_CONFIG_MAX_SCAN_NETWORKS_RESULTS CONFIG_MAX_SCAN_NETWORKS_RESULTS
#define CHIP_DEVICE_CONFIG_WIFI_SCAN_COMPLETION_TIMEOUT CONFIG_WIFI_SCAN_COMPLETION_TIMEOUT
#define CHIP_DEVICE_CONFIG_WIFI_CONNECTIVITY_TIMEOUT CONFIG_WIFI_CONNECTIVITY_TIMEOUT
#if CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP
#define CHIP_DEVICE_CONFIG_WIFI_AP_SSID_PREFIX CONFIG_WIFI_AP_SSID_PREFIX
#define CHIP_DEVICE_CONFIG_WIFI_AP_CHANNEL CONFIG_WIFI_AP_CHANNEL
#define CHIP_DEVICE_CONFIG_WIFI_AP_MAX_STATIONS CONFIG_WIFI_AP_MAX_STATIONS
#define CHIP_DEVICE_CONFIG_WIFI_AP_BEACON_INTERVAL CONFIG_WIFI_AP_BEACON_INTERVAL
#define CHIP_DEVICE_CONFIG_WIFI_AP_IDLE_TIMEOUT CONFIG_WIFI_AP_IDLE_TIMEOUT
#endif /* CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP */
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_TELEMETRY CONFIG_ENABLE_WIFI_TELEMETRY
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP | CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION
#endif // CONFIG_IDF_TARGET_ESP32H2

#define CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE CONFIG_ENABLE_CHIPOBLE
#define CHIP_DEVICE_CONFIG_ENABLE_EXTENDED_DISCOVERY CONFIG_ENABLE_EXTENDED_DISCOVERY
#define CHIP_DEVICE_CONFIG_ENABLE_COMMISSIONABLE_DEVICE_TYPE CONFIG_ENABLE_COMMISSIONABLE_DEVICE_TYPE
#define CHIP_DEVICE_CONFIG_BLE_DEVICE_NAME_PREFIX CONFIG_BLE_DEVICE_NAME_PREFIX
#define CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL_MIN CONFIG_BLE_FAST_ADVERTISING_INTERVAL_MIN
#define CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL_MAX CONFIG_BLE_FAST_ADVERTISING_INTERVAL_MAX
#define CHIP_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL_MIN CONFIG_BLE_SLOW_ADVERTISING_INTERVAL_MIN
#define CHIP_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL_MAX CONFIG_BLE_SLOW_ADVERTISING_INTERVAL_MAX
#define CHIP_DEVICE_CONFIG_CHIPOBLE_SINGLE_CONNECTION CONFIG_CHIPOBLE_SINGLE_CONNECTION
#define CHIP_DEVICE_CONFIG_ENABLE_CHIP_TIME_SERVICE_TIME_SYNC CONFIG_ENABLE_CHIP_TIME_SERVICE_TIME_SYNC
#define CHIP_DEVICE_CONFIG_CHIP_TIME_SERVICE_ENDPOINT_ID CONFIG_CHIP_TIME_SERVICE_ENDPOINT_ID
#define CHIP_DEVICE_CONFIG_DEFAULT_TIME_SYNC_INTERVAL CONFIG_DEFAULT_TIME_SYNC_INTERVAL
#define CHIP_DEVICE_CONFIG_TIME_SYNC_TIMEOUT CONFIG_TIME_SYNC_TIMEOUT
#define CHIP_DEVICE_CONFIG_SERVICE_PROVISIONING_ENDPOINT_ID CONFIG_SERVICE_PROVISIONING_ENDPOINT_ID
#define CHIP_DEVICE_CONFIG_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT CONFIG_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT
#define CHIP_DEVICE_CONFIG_SERVICE_PROVISIONING_REQUEST_TIMEOUT CONFIG_SERVICE_PROVISIONING_REQUEST_TIMEOUT
#define CHIP_DEVICE_CONFIG_ENABLE_TEST_SETUP_PARAMS CONFIG_ENABLE_TEST_SETUP_PARAMS
#define CHIP_DEVICE_CONFIG_TEST_SERIAL_NUMBER CONFIG_USE_TEST_SERIAL_NUMBER
#define CHIP_DEVICE_CONFIG_ENABLE_TRAIT_MANAGER CONFIG_ENABLE_TRAIT_MANAGER
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY CONFIG_ENABLE_THREAD_TELEMETRY
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY_FULL CONFIG_ENABLE_THREAD_TELEMETRY_FULL
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_CRIT_BUFFER_SIZE CONFIG_EVENT_LOGGING_CRIT_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_PROD_BUFFER_SIZE CONFIG_EVENT_LOGGING_PROD_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_INFO_BUFFER_SIZE CONFIG_EVENT_LOGGING_INFO_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_DEBUG_BUFFER_SIZE CONFIG_EVENT_LOGGING_DEBUG_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_LOG_PROVISIONING_HASH CONFIG_LOG_PROVISIONING_HASH
#define CHIP_DEVICE_CONFIG_CHIP_FACTORY_NAMESPACE_PARTITION CONFIG_CHIP_FACTORY_NAMESPACE_PARTITION_LABEL
#define CHIP_DEVICE_CONFIG_CHIP_CONFIG_NAMESPACE_PARTITION CONFIG_CHIP_CONFIG_NAMESPACE_PARTITION_LABEL
#define CHIP_DEVICE_CONFIG_CHIP_COUNTERS_NAMESPACE_PARTITION CONFIG_CHIP_COUNTERS_NAMESPACE_PARTITION_LABEL
#define CHIP_DEVICE_CONFIG_CHIP_KVS_NAMESPACE_PARTITION CONFIG_CHIP_KVS_NAMESPACE_PARTITION_LABEL
#define CHIP_DEVICE_CONFIG_ENABLE_DEVICE_INSTANCE_INFO_PROVIDER CONFIG_ENABLE_ESP32_DEVICE_INSTANCE_INFO_PROVIDER
