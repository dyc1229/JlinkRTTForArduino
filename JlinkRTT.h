#ifndef JLINK_RTT_H
#define JLINK_RTT_H

#include "Arduino.h"
#include "SEGGER_RTT.h"
#include "Stream.h"

class JLINKRTT : public Stream {
  public:
    JLINKRTT();
    void begin();
    int available();
    int read();
	unsigned read(unsigned BufferIndex,void* pBuffer, unsigned BufferSize);
    int availableForWrite();
    size_t write(const uint8_t ch);
    int peek();
    void flush();
    int setTerminal(char TerminalId);
    int terminalOut(char TerminalId, const char *s);
	using Print::write;
	void end();
	operator bool(){
		return true;
	}
};

extern JLINKRTT jlinkrtt;

#endif
