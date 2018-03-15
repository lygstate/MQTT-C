 #include <mqtt.h>
 #include <mqtt_details.h>
 
 ssize_t __mqtt_pack_str(uint8_t *buf, const char* str) {
    uint16_t length = strlen(str);

    /* pack string length */
    *(uint16_t*) buf = (uint16_t) htons(length);
    buf += 2;

    /* pack string */
    for(int i = 0; i < length; ++i) {
        *(buf++) = str[i];
    }
    
    /* return number of bytes consumed */
    return length + 2;
}

static const char *MQTT_ERRORS_STR[] = {
    "MQTT_UNKNOWN_ERROR",
    __ALL_MQTT_ERRORS(GENERATE_STRING)
};

const char* mqtt_error_str(enum MqttErrors error) {
    int offset = error - MQTT_ERROR_UNKNOWN;
    if (offset >= 0) {
        return MQTT_ERRORS_STR[offset];
    } else {
        return MQTT_ERRORS_STR[0];
    }
}