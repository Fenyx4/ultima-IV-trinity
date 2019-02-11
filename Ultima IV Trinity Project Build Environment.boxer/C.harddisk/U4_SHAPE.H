/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#ifndef __U4_SHAPE_H__
#define __U4_SHAPE_H__

/*deep water*/
#define TIL_00 0x00
/*medium water*/
#define TIL_MWater_01 0x01
/*shallow water*/
#define TIL_SWater_02 0x02
/*swamp*/
#define TIL_Swamp_03 0x03
/*grass*/
#define TIL_Grass_04 0x04
/*scrub*/
#define TIL_Scrub_05 0x05
/*forest*/
#define TIL_Forest_06 0x06
/*hills*/
#define TIL_Hills_07 0x07
/*mountains*/
#define TIL_Mount_08 0x08
/*dungeon*/
#define TIL_Dung_09 0x09
/*town*/
#define TIL_Town_0A 0x0A
/*castle*/
#define TIL_Castle_0B 0x0B
/*village*/
#define TIL_Village_0C 0x0C
/*LB castle left wing*/
#define TIL_CasL_0D 0x0D
/*LB castle entrance*/
#define TIL_CasEn_0E 0x0E
/*LB castle right wing*/
#define TIL_CasR_0F 0x0F

/*ship W/N/E/S*/
#define TIL_ShipW_10 0x10
#define TIL_ShipN_11 0x11
#define TIL_ShipE_12 0x12
#define TIL_ShipS_13 0x13

/*horse W/E*/
#define TIL_HorseW_14 0x14
#define TIL_HorseE_15 0x15

/*tiled floor*/
#define TIL_16 0x16
/*bridge*/
#define TIL_17 0x17
/*balloon*/
#define TIL_18 0x18
/**/
#define TIL_19 0x19
/**/
#define TIL_1A 0x1A
/*ladder up*/
#define TIL_1B 0x1B
/*ladder down*/
#define TIL_1C 0x1C
/*ruins*/
#define TIL_1D 0x1D
/*shrine*/
#define TIL_1E 0x1E
/*on foot party*/
#define TIL_1F 0x1F

/*====---- 2-tile animation "human" ----====*/

/*mage*/
#define TIL_20 0x20
/*bard*/
#define TIL_22 0x22
/*fighter*/
#define TIL_24 0x24
/*druid*/
#define TIL_26 0x26
/*tinker*/
#define TIL_28 0x28
/*paladin*/
#define TIL_2A 0x2A
/*ranger*/
#define TIL_2C 0x2C
/*shepherd*/
#define TIL_2E 0x2E

/*====---- ----====*/

#define TIL_30 0x30
#define TIL_31 0x31
#define TIL_32 0x32
#define TIL_33 0x33
#define TIL_34 0x34
#define TIL_35 0x35
#define TIL_36 0x36
#define TIL_37 0x37
/*sleep*/
#define TIL_38 0x38
/**/
#define TIL_39 0x39
/*locked door*/
#define TIL_3A 0x3A
/*door*/
#define TIL_3B 0x3B
/*chest*/
#define TIL_3C 0x3C
/*ankh*/
#define TIL_3D 0x3D
/*brick floor*/
#define TIL_3E 0x3E
/*wood floor*/
#define TIL_3F 0x3F

/*moongate 4 phases*/
#define TIL_40 0x40
#define TIL_41 0x41
#define TIL_42 0x42
#define TIL_43 0x43

/*poison field*/
#define TIL_44 0x44
/*energy field*/
#define TIL_45 0x45
/*fire field*/
#define TIL_46 0x46
/*sleep field*/
#define TIL_47 0x47

#define TIL_48 0x48
#define TIL_49 0x49
#define TIL_4A 0x4A
#define TIL_4B 0x4B
/*lava*/
#define TIL_4C 0x4C
/*missile*/
#define TIL_4D 0x4D
#define TIL_4E 0x4E
#define TIL_4F 0x4F

/*====---- 2-tile animation NPC ----====*/

/*guard*/
#define TIL_50 0x50
/*merchant*/
#define TIL_52 0x52
/*bard*/
#define TIL_54 0x54
/*jester*/
#define TIL_56 0x56
/*beggar*/
#define TIL_58 0x58
/*child*/
#define TIL_5A 0x5A
/*bull*/
#define TIL_5C 0x5C
/*lord british*/
#define TIL_5E 0x5E

/*====---- Alphabet ----====*/

#define TIL_60 0x60
#define TIL_61 0x61
#define TIL_62 0x62
#define TIL_63 0x63
#define TIL_64 0x64
#define TIL_65 0x65
#define TIL_66 0x66
#define TIL_67 0x67
#define TIL_68 0x68
#define TIL_69 0x69
#define TIL_6A 0x6A
#define TIL_6B 0x6B
#define TIL_6C 0x6C
#define TIL_6D 0x6D
#define TIL_6E 0x6E
#define TIL_6F 0x6F
#define TIL_70 0x70
#define TIL_71 0x71
#define TIL_72 0x72
#define TIL_73 0x73
#define TIL_74 0x74
#define TIL_75 0x75
#define TIL_76 0x76
#define TIL_77 0x77
#define TIL_78 0x78
#define TIL_79 0x79
/*<space>*/
#define TIL_7A 0x7A

#define TIL_7B 0x7B
#define TIL_7C 0x7C
#define TIL_7D 0x7D
#define TIL_7E 0x7E
#define TIL_7F 0x7F

/*====---- 2-tile monsters ----====*/

/*pirate*/
#define TIL_80 0x80
#define TIL_81 0x81
/*pirate*/
#define TIL_82 0x82
#define TIL_83 0x83
/*nixie*/
#define TIL_84 0x84
/*squid*/
#define TIL_86 0x86
/*serpent*/
#define TIL_88 0x88
/*seahorse*/
#define TIL_8A 0x8A
/*whirlpool*/
#define TIL_8C 0x8C
/*twister*/
#define TIL_8E 0x8E
#define TIL_8F 0x8F

/*====---- 3-tile monsters ----====*/

/*rat*/
#define TIL_90 0x90
/*bat*/
#define TIL_94 0x93
/*spider*/
#define TIL_98 0x96
/*ghost*/
#define TIL_9C 0x99
/*slime*/
#define TIL_A0 0x9C
/*troll*/
#define TIL_A4 0x9F
/*gremlin*/
#define TIL_A8 0xA2
/*mimic*/
#define TIL_AC 0xA5
/*reaper*/
#define TIL_B0 0xA8
/*insects*/
#define TIL_B4 0xAB
/*gazer*/
#define TIL_B8 0xAE
/*phantom*/
#define TIL_BC 0xB1
/*orc*/
#define TIL_C0 0xB4
/*skeleton*/
#define TIL_C4 0xB7
/*rogue*/
#define TIL_C8 0xBA
/*python*/
#define TIL_CC 0xBD
/*ettin*/
#define TIL_D0 0xC0
/*headless*/
#define TIL_D4 0xC3
/*cyclops*/
#define TIL_D8 0xC6
/*wisp*/
#define TIL_DC 0xC9
/*mage*/
#define TIL_E0 0xCC
/*lyche*/
#define TIL_E4 0xCF
/*lava lizard*/
#define TIL_E8 0xD2
#define TIL_E9 0xD3
/*zorn*/
#define TIL_EC 0xD5
/*daemon*/
#define TIL_F0 0xD8
/*hydra*/
#define TIL_F4 0xDB
/*dragon*/
#define TIL_F8 0xDE
/*balron*/
#define TIL_FC 0xE1

/*====---- 3-tile animated objects ----====*/

/*fireplace*/
#define TIL_Fireplace_1 0xE4
/*fireplace*/
#define TIL_Fireplace_2 0xE5
/*fireplace*/
#define TIL_Fireplace_3 0xE6
/*brazier*/
#define TIL_Brazier 0xE7
/*fountain*/
#define TIL_Fountain 0xEA

/*====---- new buildings and building objects ----====*/

/*tower*/
#define TIL_Tower 0xED
/*oracle good*/
#define TIL_Oracle_Good 0xEE
/*oracle destroyed*/
#define TIL_Oracle_Destroyed 0xEF
/*crypt open*/
#define TIL_Crypt_Open 0xF0
/*crypt closed*/
#define TIL_Crypt_Closed 0xF1
/*hamlet*/
#define TIL_Hamlet 0xF2
/*roof A*/
#define TIL_Roof_A 0xF3
/*roof B*/
#define TIL_Roof_B 0xF4
/*gargoyle*/
#define TIL_Gargoyle 0xF5
/*upper window*/
#define TIL_Upper_Window 0xF6
/*lower window*/
#define TIL_Lower_Window 0xF7
/*crenellations*/
#define TIL_Crenn_1 0xF8
/*crenellations*/
#define TIL_Crenn_2 0xF9
/*crenellations*/
#define TIL_Crenn_3 0xFA
/*crenellations*/
#define TIL_Crenn_4 0xFB
/*crenellations*/
#define TIL_Crenn_5 0xFC
/*crenellations*/
#define TIL_Crenn_6 0xFD
/*crenellations*/
#define TIL_Crenn_7 0xFE
/*crenellations*/
#define TIL_Crenn_8 0xFF

/*-----------Added Code for Dragons!---------------*/
/*dragon mount */
#define TIL_Dragon1 0xDE
#define TIL_Dragon2 0xDF
#define TIL_Dragon3 0xE0
#define TIL_Dragon4 0xE0

/*-----------Added Code for Dragons!---------------*/


#endif
