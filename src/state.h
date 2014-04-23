#ifndef STATE_H
#define STATE_H

#include <stdint.h>
#include <unordered_map>
#include <list>
#include "seq.h"

using namespace std;

enum Playback {Play, Stop, Record};

class State {
    private:
        unordered_map<uint16_t, Sequence> sequences;
	list<Sequence> seqList;
	Sequence *curSeq;
	Playback playback;
    public:
        string name;
	uint16_t tempo;
	uint8_t masterVol;

	void addSequence(Sequence*);
	void removeSequence(uint16_t);
	void startPlayback();
	void stopPlayback();
	void recPlayback();

	State(string);
};

#endif
