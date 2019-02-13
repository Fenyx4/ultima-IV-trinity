/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <stdlib.h>

int Horse_x = 0;
int Horse_y = 0;

char *Talk_Files[] ={
	/*Castles*/
	/*D_1682*/"LCB.TLK",
	/*D_168A*/"LYCAEUM.TLK",
	/*D_1696*/"EMPATH.TLK",
	/*D_16A1*/"SERPENT.TLK",
	/*Townes*/
	/*D_16AD*/"MOONGLOW.TLK",
	/*D_16BA*/"BRITAIN.TLK",
	/*D_16C6*/"JHELOM.TLK",
	/*D_16D1*/"YEW.TLK",
	/*D_16D9*/"MINOC.TLK",
	/*D_16E3*/"TRINSIC.TLK",
	/*D_16EF*/"SKARA.TLK",
	/*D_16F9*/"MAGINCIA.TLK",
	/*Villages*/
	/*D_1706*/"PAWS.TLK",
	/*D_170F*/"DEN.TLK",
	/*D_1717*/"VESPER.TLK",
	/*D_1722*/"COVE.TLK",
    /*Dungeons - added to give correct spacing when referencing new locatons*/
    /*0xF0 0x49*/"D",
    /*D_07A8*/"D",
    /*D_07B4*/"D",
    /*D_07C0*/"W",
    /*D_07CA*/"C",
    /*D_07D7*/"S",
    /*D_07E1*/"H",
    /*D_07EE*/"A",
    /*Shrines*/
    /*D_076D*/"B",
    /*D_0772*/"Y",
    /*D_0779*/"R",
    /*D_077D*/"G",
    /*D_0783*/"O",
    /*D_078A*/"P",
    /*D_0791*/"W",
    /*D_0797*/"B",
    /*Camps*/
    /*D_16C6*/"RIVERCA.TLK",
    /*D_16D1*/"FORESTCA.TLK",
    /*D_16C6*/"MOUNTCA.TLK",
    /*D_16D1*/"SWAMPCA.TLK",
    /*D_16C6*/"PLAINSC1.TLK",
    /*D_16D1*/"VALLEYCA.TLK",
    /*D_16C6*/"FARMCA.TLK",
    /*D_16D1*/"VALLEYCA.TLK",
    /*Crypts*/
    /*D_07EE*/"M",
    /*D_07EE*/"M",
    /*D_07EE*/"E",
    /*Oracle*/
    /*D_07EE*/"L",
    /*D_07EE*/"C",
    /*D_07EE*/"T"

};

char *Talk_Files_2[] ={
    /*Castles*/
    /*D_1682*/"LCB.TLK",
    /*D_168A*/"LYCAEUM2.TLK",
    /*D_1696*/"EMPATH2.TLK",
    /*D_16A1*/"SERPENT2.TLK",
    /*Townes*/
    /*D_16AD*/"MOONGLO2.TLK",
    /*D_16BA*/"BRITAIN2.TLK",
    /*D_16C6*/"JHELOM2.TLK",
    /*D_16D1*/"YEW2.TLK",
    /*D_16D9*/"MINOC2.TLK",
    /*D_16E3*/"TRINSIC2.TLK",
    /*D_16EF*/"SKARA2.TLK",
    /*D_16F9*/"MAGINCI2.TLK",
    /*Villages*/
    /*D_1706*/"PAWS.TLK",
    /*D_170F*/"DEN.TLK",
    /*D_1717*/"VESPER.TLK",
    /*D_1722*/"COVE.TLK",
    /*Dungeons - added to give correct spacing when referencing new locatons*/
    /*0xF0 0x49*/"D",
    /*D_07A8*/"D",
    /*D_07B4*/"D",
    /*D_07C0*/"W",
    /*D_07CA*/"C",
    /*D_07D7*/"S",
    /*D_07E1*/"H",
    /*D_07EE*/"A",
    /*Shrines*/
    /*D_076D*/"B",
    /*D_0772*/"Y",
    /*D_0779*/"R",
    /*D_077D*/"G",
    /*D_0783*/"O",
    /*D_078A*/"P",
    /*D_0791*/"W",
    /*D_0797*/"B",
    /*Camps*/
    /*D_16C6*/"RIVERCA.TLK",
    /*D_16D1*/"FORESTCA.TLK",
    /*D_16C6*/"MOUNTCA.TLK",
    /*D_16D1*/"SWAMPCA.TLK",
    /*D_16C6*/"PLAINSC2.TLK",
    /*D_16D1*/"VALLEYCA.TLK",
    /*D_16C6*/"FARMCA.TLK",
    /*D_16D1*/"VALLEYCA.TLK",
    /*Crypts*/
    /*D_07EE*/"M",
    /*D_07EE*/"M",
    /*D_07EE*/"E",
    /*Oracle*/
    /*D_07EE*/"L",
    /*D_07EE*/"C",
    /*D_07EE*/"T"
};

char *Talk_Files_B[] ={
    /*Castles*/
    /*D_1682*/"LCBB.TLK",
    /*D_168A*/"LYCAEUMB.TLK",
    /*D_1696*/"EMPATHB.TLK",
    /*D_16A1*/"SERPENTB.TLK",
    /*Townes*/
    /*D_16AD*/"MOONGLOB.TLK",
    /*D_16BA*/"BRITAINB.TLK",
    /*D_16C6*/"JHELOMB.TLK",
    /*D_16D1*/"YEWB.TLK",
    /*D_16D9*/"MINOCB.TLK",
    /*D_16E3*/"TRINSICB.TLK",
    /*D_16EF*/"SKARAB.TLK",
    /*D_16F9*/"MAGINCIB.TLK",
    /*Villages*/
    /*D_1706*/"PAWS.TLK",
    /*D_170F*/"DEN.TLK",
    /*D_1717*/"VESPER.TLK",
    /*D_1722*/"COVE.TLK",
    /*Dungeons - added to give correct spacing when referencing new locatons*/
    /*0xF0 0x49*/"D",
    /*D_07A8*/"D",
    /*D_07B4*/"D",
    /*D_07C0*/"W",
    /*D_07CA*/"C",
    /*D_07D7*/"S",
    /*D_07E1*/"H",
    /*D_07EE*/"A",
    /*Shrines*/
    /*D_076D*/"B",
    /*D_0772*/"Y",
    /*D_0779*/"R",
    /*D_077D*/"G",
    /*D_0783*/"O",
    /*D_078A*/"P",
    /*D_0791*/"W",
    /*D_0797*/"B",
    /*Camps*/
    /*D_16C6*/"RIVERCA.TLK",
    /*D_16D1*/"FORESTCA.TLK",
    /*D_16C6*/"MOUNTCA.TLK",
    /*D_16D1*/"SWAMPCA.TLK",
    /*D_16C6*/"PLAINSCB.TLK",
    /*D_16D1*/"VALLEYCA.TLK",
    /*D_16C6*/"FARMCA.TLK",
    /*D_16D1*/"VALLEYCA.TLK",
    /*Crypts*/
    /*D_07EE*/"M",
    /*D_07EE*/"M",
    /*D_07EE*/"E",
    /*Oracle*/
    /*D_07EE*/"L",
    /*D_07EE*/"C",
    /*D_07EE*/"T"
};



/*load casle/towne/village files*/
Load_Towne(bp04)
unsigned bp04;
{
	if(Save("OUTMONST.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
		exit(3);
	if(Load(Towne_Castle_Village[bp04 - 0x01], sizeof(struct t_500), &D_8742) == -1)
		exit(3);
	File_TLK = File_TLK_Buff = dopen(Talk_Files[Party._loc - 1], 0);
    File_TLK_2 = dopen(Talk_Files_2[Party._loc - 1], 0);
    File_TLK_B = dopen(Talk_Files_B[Party._loc - 1], 0);
	CurMode = MOD_BUILDING;
}

Load_Towne_2nd(bp04,bp02)
unsigned bp04,bp02;
{

    if(Load(Second_Floor[bp04 - 0x01 + (bp02 * 40)], sizeof(struct t_500), &D_8742) == -1)
        exit(3);
    File_TLK = File_TLK_2;
}

/*load dungeon files*/
EXP_Load_Dungeon()
{
	register int si;
    char *dun_choi;

    /*made party._loc one bigger to ensure that Abyss is loaded correctly?*/
    if(Party._loc <= 0x19) {
        dun_choi = Dungeons[Party._loc - 0x11];
    } else {
        dun_choi = Crypts[Party._loc - 0x29];
    }
        if(Load(dun_choi, sizeof(tMap8x8x8), &(D_8742._map)) == -1)
            exit(3);
        File_DNG = dopen(dun_choi, 0);
        for(si = 0x1f; si >= 0; si --)
            D_8742._npc._tile[si] = 0;
    
}

EXP_Set_Dungeon()
{
	EXP_Load_Dungeon();
	CurMode = MOD_DUNGEON;
	Party._dir = DIR_E;
	Party._z = 0;
	DNG_main();
}

/*enter dungeon*/
Enter_Dungeon()
{
	Gra_CR();
	Gra_CR();
    
    /*-----------Modified Code for Dragons!---------------*/
    /*---Gives unique messages for Horse or Dragon mount--*/
    if(Party._tile >= TIL_Dragon1 && Party._tile <= TIL_Dragon4) {
        Party._loc = 0;
        w_No_Dragon();
        return;
    }
    
	if(Party._tile == TIL_HorseW_14 || Party._tile == TIL_HorseE_15) {
    /*-----------Modified Code for Dragons!---------------*/
        
		Party._loc = 0;
		w_OnlyOnFoot();
		return;
	}
	Party._x = Party._y = 1;
	if(Save(/*D_1758*/"OUTMONST.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
		exit(3);
	EXP_Set_Dungeon();
}

/*enter towne*/
Enter_Towne()
{
	register int si;
    
    /*-----------Added Code for Dragons!---------------*/
    /*-----Prevents dragons from entering townes-------*/
    if(Party._tile >= TIL_Dragon1 && Party._tile <= TIL_Dragon4) {
        Party._loc = 0;
        w_No_Dragon();
        return;
    }
    /*-----------Added Code for Dragons!---------------*/
    
    if (Party._tile == TIL_HorseW_14 || Party._tile == TIL_HorseE_15){
    /*resets the horse coordinates for a later check whether to 'restore' a horse*/
    HorseTown = 1;
    }

	u4_puts(D_Locations[Party._loc - 1]);
	Gra_CR();
	Gra_CR();
    
    /*added to give new towns unique start coords*/
    if (Party._loc == 0x24){
        Party._y = D_959C.y = 0x0f;
        Party._x = D_959C.x = 0x01;
    }
    else if ((Party._loc) < 5) {
        Party._y = D_959C.y = 0x1e;
        Party._x = D_959C.x = 0x0f;
    }
    else if((Party._loc) < 17  &&  (Party._loc) > 4) {
        Party._y = D_959C.y = 15;
        Party._x = D_959C.x = 1;
    }
    else {
        Party._y = D_959C.y = 0x13;
        Party._x = D_959C.x = 0x1e;
    }
    
	Load_Towne(Party._loc);
    

    /*removes characters who join, from towne, if joined*/
    EXP_Clear_PartyNPC();

}


/*removes characters who join, from towne, if joined, after coming down from second story*/
EXP_Clear_PartyNPC()
{
    register int si;

    if((Party._loc - 0x05) < 8) {
        for(si = Party._members; --si >= 1; ) {
            if(Party.chara[si]._class == (Party._loc - 0x05)) {
                D_8742._npc._tile[31] = D_8742._npc._gtile[31] = D_8742._npc._var[31] = 0;
            }
        }
    }
}

/*enter the abyss?*/
EXP_Enter_Abyss()
{
	if((
		(Party.mItems >> 3) &
		(Party.mItems >> 4) &
		(Party.mItems >> 2) &
		(Party.mItems >> 11) &
		(Party.mItems >> 12) &
		(Party.mItems >> 10)
	) & 1) {
		u4_puts(D_Locations[Party._loc - 1]);
		Enter_Dungeon();
	} else {
		Party._loc = 0;
		w_Cant_t();
	}
}

CMD_Enter()
{
	register int si;
    
    /*-----------Modified Code for Dragons!---------------*/
    /*----Returns unqiue negative responses when flying---*/
    if(Party.f_1dc == 1){
        W_DriftOnly();
        return;
    }

	u4_puts("Enter ");
	if(Party._loc != 0) {
    /*-----------Modified Code for Dragons!---------------*/
        
		w_What();
		return;
	}
    /*Need to Change to allow more Maps*/
    /*Must be incremented each time a map is added. Automate?*/
	si = 45;
	while(si >= 0) {
#ifdef WIN32
		if(Party._x == (unsigned char)D_0844[si] && Party._y == (unsigned char)D_0864[si])
#else
		if(Party._x == D_0844[si] && Party._y == D_0864[si])
#endif
			break;
		si--;
	}
	if(si == -1) {
		w_What();
		return;
	}
	Party._loc = si + 1;
	Party.out_x = Party._x;
	Party.out_y = Party._y;
	switch(D_8742._map.x32x32[D_959C.y][D_959C.x]) {
        case TIL_Dung_09: case TIL_Crypt_Open:
			u4_puts("dungeon!\n\n");
			u4_puts(D_Locations[Party._loc - 1]);
			Enter_Dungeon();
		break;
		case TIL_Town_0A:
			u4_puts("towne!\n\n");
			Enter_Towne();
		break;
		case TIL_Castle_0B: case TIL_CasEn_0E:
			u4_puts("castle!\n\n");
            Enter_Towne();
		break;
            
        /*added cases for 3 sprite NPCs and new tiles */
        case TIL_Hamlet:
            u4_puts("hamlet!\n\n");
            Enter_Towne();
        break;
        case TIL_Village_0C:
            u4_puts("village!\n\n");
            Enter_Towne();
            
		break;
		case TIL_1D:
			u4_puts("ruin!\n\n");
			Enter_Towne();
		break;
		case TIL_4C:
			if(Party._x != 0xe9 || Party._y != 0xe9) {
				w_What();
				return;
			}
		case TIL_46:
			EXP_Enter_Abyss();
		break;
        case TIL_Oracle_Good:
            u4_puts("Oracle!");
            /*u4_puts("the Oracle of\n");*/
            /*u4_puts(D_Principles[Party._loc - 0x2c]);*/
            Gra_CR();
            Enter_Oracle();
        break;
		case TIL_1E:
			u4_puts("the Shrine of\n");
			u4_puts(D_Virtues[Party._loc - 0x19]);
			Gra_CR();
			Enter_Shrine();
		break;
		default:
			w_What();
			return;
	}
}

EXP_OnFoot()
{
	register int si;
    
	for(si = 31; si >= 8 ;si --) {
		if(D_8742._npc._tile[si] == 0)
			break;
	}
	if(si == 7)
		si = U4_RND1(15) | 0x10;
        /*added to fix mounting dragons */
        if(Party._tile >= TIL_Dragon1 && Party._tile <= TIL_Dragon4)
            Party._tile = TIL_Dragon1;
        /*added to fix mounting dragons */
	D_8742._npc._gtile[si] = D_8742._npc._tile[si] = Party._tile;
	D_8742._npc._x[si] = Party._x;
	D_8742._npc._y[si] = Party._y;
    
    /*-----------Modified Code for Dragons!---------------*/
    /*-Hit points for unmounted Dragons and Ship stored here--*/
	D_8742._npc._tlkidx[si] = Party._ship;
    /*-----------Modified Code for Dragons!---------------*/
    
	Party._tile = TIL_1F;
	Gra_CR();
}

CMD_X_it()
{
	u4_puts("X-it ");
if((Party._tile < TIL_16) ||  (Party._tile >= TIL_Dragon1 && Party._tile <= TIL_Dragon4 && Party.f_1dc == 0)) {
    /*-----------Modified Code for Dragons!---------------*/
        
        if(CurMode == MOD_BUILDING){
            Party._tile = TIL_1F;
            DoublePace = 0;
            D_8742._npc._tile[ship_x] = D_8742._npc._gtile[ship_x] = TIL_HorseE_15;
            D_8742._npc._x[ship_x] = Party._x;
            D_8742._npc._y[ship_x] = Party._y;
            Horse_x = Party._x;
            Horse_y = Party._y;
            D_8742._npc._var[ship_x] = 1;
            D_8742._npc._tlkidx[ship_x] = 0;
            Gra_CR();
        }
        else {
            DoublePace = 0;
            EXP_OnFoot();
        }
        
        
	} else if(Party._tile == TIL_18 && Party.f_1dc == 0) {
		EXP_OnFoot();
        
    /*-----------Added Code for Dragons!---------------*/
    /*-----------Modified Code for Dragons!------------*/
    } else if(((Party._tile >= TIL_Dragon1 && Party._tile <= TIL_Dragon4) || Party._tile == TIL_18) && Party.f_1dc == 1){
        W_DriftOnly();
    /*-----------Added Code for Dragons!---------------*/
        
	} else {
		w_What();
	}
}

EXP_Restore_Horse()
{
    if (HorseTown == 1){
        D_8742._npc._tile[ship_x] = D_8742._npc._gtile[ship_x] = TIL_HorseE_15;
        D_8742._npc._x[ship_x] = Horse_x;
        D_8742._npc._y[ship_x] = Horse_y;
        D_8742._npc._var[ship_x] = 1;
    }
}

EXP_Mount(bp04)
unsigned bp04;
{
	register int si;

	for(si = 31; si >= 8; si --) {
		if(
			Party._x == D_8742._npc._x[si] &&
           Party._y == D_8742._npc._y[si] &&
           bp04 == (D_8742._npc._tile[si])
		) break;
	}
	if(si != 7)
		D_8742._npc._gtile[si] = D_8742._npc._tile[si]  = 0;
        ship_x = si;
		Party._tile = tile_cur;
}

CMD_Board()
{
    /*-----------Added Code for Dragons!---------------*/
    register int si;
    /*-----------Added Code for Dragons!---------------*/
    
	if(Party._tile != TIL_1F) {
		u4_puts("Board: ");
		w_Cant_t();
		return;
	}
	if(tile_cur == TIL_HorseW_14 || tile_cur == TIL_HorseE_15) {
        if(CurMode == MOD_BUILDING){
            EXP_Mount(tile_cur);
            D_8742._npc._tile[0] = 0;
            u4_puts("Mount Horse!\n");
            return;        }
        else {
            EXP_Mount(tile_cur);
            u4_puts("Mount Horse!\n");
            return;
        }
	}
    
    /*-----------Added Code for Dragons!---------------*/
    /*Addeds mounting, and new handling for hit points-*/
    if(tile_cur >= TIL_Dragon1 && tile_cur <= TIL_Dragon4) {
        EXP_Mount(TIL_Dragon1);
        u4_puts("Mount Dragon!\n");
        /*Party._ship = 50;*/
        
        /*saves the dragon's hitpoints as the party's ship hitpoints */
       for(si = 31; si >= 8 ;si --) {
            if(D_8742._npc._x[si] == Party._x && D_8742._npc._y[si] == Party._y){
                Party._ship = D_8742._npc._tlkidx[si];
            }
        }
        
        return;
    }
    /*-----------Added Code for Dragons!---------------*/
    
	u4_puts("Board ");
	if(tile_cur == TIL_18) {
		EXP_Mount(tile_cur);
		u4_puts("Balloon!\n");
		Party.f_1dc = 0;
		return;
	}
	if(tile_cur < TIL_ShipW_10 || tile_cur > TIL_ShipS_13) {
		w_What();
		return;
	}
	EXP_Mount(tile_cur);
	u4_puts("Frigate!\n");
    
    /*-----------Modified Code for Dragons!---------------*/
    /*-Removed because no longer needed with new hp code--*/
    /*if(ship_x != Party._x || ship_y != Party._y) {*/
    /*-----------Modified Code for Dragons!---------------*/

    
    /*-----------Added Code for Dragons!---------------*/
    /*--Aligns new HP handling for Dragons with Ships--*/
		/*Party._ship = 50;*/

        for(si = 31; si >= 8 ;si --) {
            if(D_8742._npc._x[si] == Party._x && D_8742._npc._y[si] == Party._y){
                Party._ship = D_8742._npc._tlkidx[si];
            }
        }
    /*}*/
    /*-----------Added Code for Dragons!---------------*/
    
}

CMD_Yell()
{
	u4_puts("Yell ");
	if(Party._tile == TIL_HorseW_14 || Party._tile == TIL_HorseE_15) {
		if(DoublePace ^= 1)
			u4_puts(/*D_17E9*/"Giddyup!\n");
		else
			u4_puts(/*D_17F3*/"Whoa!\n");
	} else {
		w_What();
	}
}

unsigned D_17FA = 0;/*current opened door's x*/
unsigned D_17FC = 0;/*current opened door's y*/
unsigned D_17FE = 0;/*current opened door's delay*/

/*automatic door close*/
C_431D()
{
	if(CurMode == MOD_BUILDING && D_17FE) {
		if(--D_17FE == 0)
			D_8742._map.x32x32[D_17FC][D_17FA] = TIL_3B;
	} else {
		D_17FE = 0;
	}
}

CMD_Open()
{
	unsigned bp_02, bp_04;

	while(D_17FE)
		C_431D();
	if(CurMode != MOD_BUILDING) {
		u4_puts("Open: ");
		w_NotHere();
		return;
	}
	AskDir("Open: ", &bp_02, &bp_04);
	if(!(bp_02 | bp_04))
		return;
    
    /* tweaked for 3 sprite NPC's to allow north south doors */
	if((bp_02 + Party._x) > 0x1f) {
		w_NotHere();
	} else {
		register unsigned char *si;

		si = &(D_8742._map.x32x32[bp_04 + Party._y][bp_02 + Party._x]);
    /* tweaked for 3 sprite NPC's to allow north south doors */

		if(*si == TIL_3A) {
			w_Cant_t();
		} else if(*si == TIL_3B) {
			D_17FA = (bp_02 + Party._x);
            
            /* tweaked for 3 sprite NPC's to allow north south doors */
			D_17FC = (bp_04 + Party._y);
            /* tweaked for 3 sprite NPC's to allow north south doors */
            
			D_17FE = 5;
			*si = TIL_3E;
			u4_puts("\nOpened!\n");
		} else {
			w_NotHere();
		}
	}
}

CMD_Jimmy()
{
	int bp_04, bp_02;

	u4_puts(/*D_1818*/"Jimmy lock!\n");
	AskDir(/*D_1825*/"Dir: ", &bp_02, &bp_04);
	if(!(bp_02 | bp_04))
		return;
    
    /* tweaked for 3 sprite NPC's to allow north south doors */
	if(CurMode != MOD_BUILDING || (bp_02 + Party._x) > 0x1f) {
		w_NotHere();
	} else {
		register unsigned char *si;

		si = &(D_8742._map.x32x32[bp_04 + Party._y][bp_02 + Party._x]);
    /* tweaked for 3 sprite NPC's to allow north south doors */

		if(*si != TIL_3A) {
			w_NotHere();
			return;
		}
		if(Party._keys == 0) {
			u4_puts(/*D_182B*/"No keys left!\n");
			return;
		}
		Party._keys --;
		*si = TIL_3B;
	}
}

CMD_Klimb()
{
    while(D_17FE)
        C_431D();
	u4_puts("Klimb ");
    
	if(Party._loc == 0) {
        
        /*-----------Modified Code for Dragons!---------------*/
		if(Party._tile != TIL_18 && (!(Party._tile >= TIL_Dragon1 && Party._tile <= TIL_Dragon4))) {
        /*-----------Modified Code for Dragons!---------------*/
            
			w_What();
			return;
		}
		u4_puts("altitude\n");
        
        /*-----------Modified Code for Dragons!---------------*/
        /*-----------Modified Code for Dragons!---------------*/
        DoublePace = 1;
        /*-----------Modified Code for Dragons!---------------*/
        
		Party.f_1dc = 1;
		D_9440 = 0;
		return;
	}
    if(tile_cur != TIL_1B){
        w_What();
        return;
    }
    if(Party._tile != TIL_1F) {
        Gra_CR();
        w_OnlyOnFoot();
        return;
    }
    if(tile_cur == TIL_1B) {
        u4_puts("ladder!\n");
        Load_Towne_2nd(Party._loc,(Party._z + 2));
        Party._z++;
        if(Party._z == 0) {
            EXP_Clear_PartyNPC();
            EXP_Restore_Horse();
        }
        return;

    }
    else {
		w_What();
	}
}

CMD_Descend()
{
    while(D_17FE)
        C_431D();
    u4_puts(/*D_1886*/"Descend ");
    
    /*-----------Modified Code for Dragons!---------------*/
    if(Party.f_1dc == 1){
        
        if(Party._tile == TIL_18) {
            u4_puts("Land Balloon\n");
            if(tile_cur != TIL_Grass_04) {
                sound(1);
                w_NotHere();
                return;
            }
        }
        else if(Party._tile >= TIL_Dragon1 && Party._tile <= TIL_Dragon4) {
            u4_puts("Land Dragon\n");
            if(!(tile_cur >= TIL_Swamp_03 && tile_cur <= TIL_Mount_08)) {
                sound(1);
                w_NotHere();
                return;
            }
        }
        
    /*-----------Modified Code for Dragons!---------------*/
            
		if(Party.f_1dc == 0) {
			u4_puts(/*D_1875*/"Already Landed!\n");
			return;
		}
        
        
        /*-----------Modified Code for Dragons!---------------*/
        DoublePace = 0;
        /*-----------Modified Code for Dragons!---------------*/
        
		Party.f_1dc = 0;
		D_9440 = 1;
		return;
	}
    if(tile_cur != TIL_1C){
        w_What();
        return;
    }
    if(Party._tile != TIL_1F) {
        Gra_CR();
        w_OnlyOnFoot();
        return;
    }
    if(tile_cur == TIL_1C) {
        if(Party._y == 2 && Party._loc == 0x01) {
            u4_puts("into the depths!\n");
            Party.out_x = 0xef;
            Party.out_y = 0xf0;
            Party._y = Party._x = 5;
            Party._loc = 0x17;
            EXP_Set_Dungeon();
            return;
        }
        u4_puts("ladder!\n");
        Load_Towne_2nd(Party._loc,Party._z);
        Party._z--;
        if(Party._z == 0) {
            EXP_Clear_PartyNPC();
            EXP_Restore_Horse();
        }
        return;
        
    }
    else {
        w_What();
    }

}
