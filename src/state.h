#ifndef STATE_H
#define STATE_H

enum Playback {Play, Stop, Record};

class State {
    private:
        unordered_map<uint16_t, *Sequence> sequences;
	list<*Sequence> seqList;
	*Sequence curSeq;
	playback Playback;
    public:
        string name;
	uint16_t tempo;
	uint8_t masterVol;

	void addSequence(*Sequence);
	void removeSequence(uint16_t);
	void startPlayback();
	void stopPlayback();
	void recPlayback();

	State(string);
	~State();
}

#endif
