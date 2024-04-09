#ifndef _LCOM_I8042_H_
#define _LCOM_I8042_H_

#define IRQ_KEYBOARD    1

#define BRK_ESC 0x81
#define TWO_BYTE_SCANCODE 0xE0

#define TIMEOUT_ERROR BIT(6)
#define PARITY_ERROR BIT(7)
#define IN_BUFFER_FULL BIT(1)
#define OUT_BUFFER_FULL BIT(0)

#define KBC_OUT_BUF 0x60
#define KBC_WRITE_CMD_BYTE 0x60
#define KBC_STATUS_REGISTER 0x64
#define KBC_IN_BUFFER 0x64
#define KBC_READ_CMD 0x20

#define DELAY_US    20000


#endif /* _LCOM_I8042_H_ */
