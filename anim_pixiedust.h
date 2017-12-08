#ifndef anim_pixiedust_h
#define anim_pixiedust_h

#include "anim.h"

// brigthness animation amplitude shift. true BrA amplitude is calculated as (0..127) value shifted right by this amount
#define BRA_AMP_SHIFT 2
// brigthness animation amplitude offset
#define BRA_OFFSET (222-32)
// length of "dust" transition between colors, number of LEDs
#define DUST_LENGTH 20

class AnimPixieDust : public Anim {
private:
    //current color
    Color curColor = Color(0);
    //previous color
    Color prevColor = Color(0);
    //brigthness animation (BrA) current initial phase
    byte braPhase;
    //braPhase change speed 
    byte braPhaseSpd=5;
    //BrA frequency (spatial)
    byte braFreq=150;

    //phase of the animation (in fact - index of LED that changes color)
    int phase = 0; 

    const Color sparkleColor = Color(0xFFFFFF);

protected:
        virtual void runImpl();
        virtual void setUp();
};
#endif