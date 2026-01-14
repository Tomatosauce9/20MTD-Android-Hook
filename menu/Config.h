//
// Created by Administrator on 2026/1/11.
//

#ifndef INC_20MINUTESTILLDAWNMOD_CONFIG_H
#define INC_20MINUTESTILLDAWNMOD_CONFIG_H

struct Config {
    //菜单开关
    bool isModifyGameData{false};      //大厅修改
    bool isModifyPlayerData{false};    //对局修改
    bool isHealth{false};              //血量修改开关
    bool isGodMode{false};              //无敌模式开关
    bool isGun{false};                 //武器修改开关
    bool autoFire{false};              //自动开火
    bool isPlayerAttr{false};       //玩家属性

    //血量属性
    int health{4};          //当前血量
    int shieldHealth{0};    //当前护盾血量
//    int healthMax{4};       //最大血量
//    int shieldHealthMax{0}; //最大护盾血量

    //武器属性
    float damage{20.0f};          //伤害
    float shotCooldown{0.25f};    //冷却
    int Ammo{6};              //子弹容量
    int maxAmmo{6};              //子弹最大容量
    float reloadDuration{1.0f};  //换弹时间
    int numOfProjectiles{1};      //射出数量
    float spread{0.0f};           //散射
    float knockback{2.0f};        //击退
    float projectileSpeed{15.0f}; //飞行速度
    int bounce{0};                 //弹射
    int piercing{0};               //穿透
    float inaccuracy{10.0f};        //随机偏移

    //其他
    int startHealth{4}; //初始血量
    float moveSpeed{3.0f}; //移动速度
    float shootMoveSpeedMultiplier{0.35f}; //移动速度
    float xPcount{1};
};


extern Config cfg;

#endif //INC_20MINUTESTILLDAWNMOD_CONFIG_H
