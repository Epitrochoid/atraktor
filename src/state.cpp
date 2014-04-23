#include <stdint.h>
#include <string>
#include <unordered_map>
#include <list>
#include "seq.h"
#include "state.h"

State::State(string name) {
    this->name = name;
    curSeq = new Sequence();
    addSequence(curSeq);
}

void State::addSequence(Sequence *seq) {
}

void State::removeSequence(uint16_t key) {
}

void State::startPlayback() {
    playback = Play;
}

void State::stopPlayback() {
    playback = Stop;
}

void State::recPlayback() {
    playback = Record;
}
