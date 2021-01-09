#include "JlinkRTT.h"

JLINKRTT::JLINKRTT() {
    // SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0,
    // SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);
}

void JLINKRTT::begin() {}

int JLINKRTT::available() { return SEGGER_RTT_HasKey(); }

int JLINKRTT::read() { uint8_t c = SEGGER_RTT_GetKey(); }

unsigned read(unsigned BufferIndex, void *pBuffer, unsigned BufferSize) {
    return SEGGER_RTT_Read(BufferIndex, pBuffer, BufferSize);
}

int JLINKRTT::availableForWrite() { return 1; }

size_t JLINKRTT::write(const uint8_t ch) {
    SEGGER_RTT_Write(0, &ch, 1);
    return 1;
}

int JLINKRTT::peek() { return 1; }

void JLINKRTT::flush(void){};

int JLINKRTT::setTerminal(char TerminalId) {
    return SEGGER_RTT_SetTerminal(TerminalId);
}
int JLINKRTT::terminalOut(char TerminalId, const char *s) {
    return SEGGER_RTT_TerminalOut(TerminalId, s);
}

void JLINKRTT::end(void) {}


JLINKRTT jlinkrtt;