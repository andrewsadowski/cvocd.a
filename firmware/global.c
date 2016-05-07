////////////////////////////////////////////////////////////
//
// MINI MIDI CV
//
// GLOBAL SETTINGS MODULE
//
////////////////////////////////////////////////////////////

// INCLUDE FILES
#include <system.h>
#include <memory.h>
#include "cv-strip.h"


//
// GLOBAL DATA
//
byte g_chan = DEFAULT_MIDI_CHANNEL; // default MIDI channel
//byte g_accent_vel = DEFAULT_ACCENT_VELOCITY; // accent velocity
byte g_gate_duration = DEFAULT_GATE_DURATION; // default gate duration

////////////////////////////////////////////////////////////
// CONFIGURE A GLOBAL SETTING
byte global_nrpn(byte param_lo, byte value_hi, byte value_lo)
{
	switch(param_lo) {
		// GLOBAL DEFAULT MIDI CHANNEL
	case NRPNL_CHAN:
		switch(value_hi) {
		default:
		case NRPVH_CHAN_SPECIFIC:
			if(value_lo >= 1 && value_lo <= 16) {
				g_chan = value_lo-1;
				return 1;
			}		
			break;
		}
		break;	

		
	////////////////////////////////////////////////////////////////
	// SELECT GATE DURATION
	case NRPNL_GATE_DUR:
		switch(value_hi) {
		case NRPVH_DUR_MS:
			g_gate_duration = value_lo;
			return 1;
		}
		break;
	}
	return 0;
}

void global_init() {
}
