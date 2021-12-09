/*
//- 设备类型
#define DEVICETYPE_UNKNOWN   0
#define DEVICETYPE_CON      1
#define DEVICETYPE_SW       2
#define DEVICETYPE_HOST     3
#define DEVICETYPE_GW       4

//- 设备状态
#define STATE_PASS_NONE     0x00
#define STATE_PASS_AUTH     0x01
#define STATE_PASS_DHCP     0x02
#define STATE_PASS_ALL      0x03

//- 端口状态
#define PORTSTATE_DOWN      0x00
#define PORTSTATE_UP        0x01
#define PORTSTATE_BLOCK     0x02

//- 端口能力
#define PORTCAPABILITY_DOWN           0x00
#define PORTCAPABILITY_RECIVE         0x01
#define PORTCAPABILITY_FORWARD        0x02
#define PORTCAPABILITY_PACKETIN       0x04

//- 端口速率
#define PORTRATE_100Mb          0x00
#define PORTRATE_1000Mb         0x01
#define PORTRATE_10000Mb        0x02


*/

typedef string MACString
struct DeviceMSGThrift{
    1: i8 type,
    2: i8 state,
    3: i32 authTime,
    4: i32 dhcpTime,
    5: string ip,
    6: string colonyID,
    7: i8 swCapability,
    8: i8 forwardCapability,
    9: i32 linkNum,
    10: list<string> peers, 
    11: list<i8> portCapability,
    12: list<i8> portState,
    13: list<i8> portRate,

}

typedef string ColonyIDString
struct SafeParamThrift{
    1: i8 checkMethod,
    2: i8 checkAlg,
    3: i8 encrypMethod,
    4: i8 encrypAlg,
    5: i16 randNum,

}



service ConService{
    map<MACString,DeviceMSGThrift> getTopo(),
    map<ColonyIDString,SafeParamThrift> getSafeParam(),
    i8 getCMode();
    i8 setCMode(1:i8 mode);
}

