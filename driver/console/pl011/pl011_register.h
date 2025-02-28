#ifndef PL011_REGISTER__H__
#define PL011_REGISTER__H__

/* PL011 Register Offset */
                                                /* Type     Reset       Width   Description */
#define UARTDR                      0x000       /* RW       0x---       12/8    Data Register */
#define UARTRSR                     0x004       /* RO       0x0         4       Receive Status Register */
#define UARTECR                     UARTRSR     /* WC       0x0         0       Receive Error Clear Register */
#define UARTFR                      0x018       /* RO       0b-10010--- 9       Flag Register */
#define UARTILPR                    0x020       /* RW       0x00        8       IrDA Low-Power Counter Register */
#define UARTIBRD                    0x024       /* RW       0x0000      16      Integer Baud Rate Register*/
#define UARTFBRD                    0x028       /* RW       0x00        6       Fractional Baud Rate Register */
#define UARTLCR_H                   0x02C       /* RW       0x00        8       Line Control Register */
#define UARTCR                      0x030       /* RW       0x0300      16      Control Register */
#define UARTIFLS                    0x034       /* RW       0x12        6       Interrupt FIFO Level Select Register */
#define UARTIMSC                    0x038       /* RW       0x000       11      Interrupt Mask Set/Clear Register */
#define UARTRIS                     0x03C       /* RO       0x00-       11      Raw Interrupt Status Register */
#define UARTMIS                     0x040       /* RO       0x00-       11      Masked Interrupt Status Register */
#define UARTICR                     0x044       /* WO       -           11      Interrupt Clear Register */
#define UARTDMACR                   0x048       /* RW       0x00        3       DMA Control Register */
#define UARTPeriphID0               0xFE0       /* RO       0x11        8       UARTPeriphID0 Register */
#define UARTPCellID0                0xFF0       /* RO       0x0D        8       UARTPCellID0 Register */

/* Data Register, UARTDR */
#define UARTDR_OE_SHIFT             11  /* Overrun error.
                                           This bit is set to 1 if data is received and the receive FIFO is already full.
                                           This is cleared to 0 once there is an empty space in the FIFO and a new character can be written to it. */
#define UARTDR_BE_SHIFT             10  /* Break error.
                                          This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity and stop bits).
                                          In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs, only one 0 character is loaded into the FIFO.
                                          The next character is only enabled after the receive data input goes to a 1 (marking state), and the next valid start bit is received. */
#define UARTDR_PE_SHIFT             9   /* Parity error.
                                           When set to 1, it indicates that the parity of the received data character does not match the parity that the EPS and SPS bits in the Line Control Register, UARTLCR_H on page 3-12 select.
                                           In FIFO mode, this error is associated with the character at the top of the FIFO. */
#define UARTDR_FE_SHIFT             8   /* Framing error.
                                           When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1).
                                           In FIFO mode, this error is associated with the character at the top of the FIFO. */
#define UARTDR_DATA_SHIFT           0   /* Receive (read) data character.
                                           Transmit (write) data character. */

/* Receive Status Register/Error Clear Register, UARTRSR/UARTECR */
#define UARTRSR_OE_SHIFT            3   /* Overrun error.
                                           This bit is set to 1 if data is received and the FIFO is already full.
                                           This bit is cleared to 0 by a write to UARTECR.
                                           The FIFO contents remain valid because no more data is written when the FIFO is full, only the contents of the shift register are overwritten. 
                                           The CPU must now read the data, to empty the FIFO. */
#define UARTRSR_BE_SHIFT            2   /* Break error.
                                           This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity, and stop bits).
                                           This bit is cleared to 0 after a write to UARTECR.
                                           In FIFO mode, this error is associated with the character at the top of the FIFO. When a break occurs, only one 0 character is loaded into the FIFO. 
                                           The next character is only enabled after the receive data input goes to a 1 (marking state) and the next valid start bit is received. */
#define UARTRSR_PE_SHIFT            1   /* Parity error.
                                           When set to 1, it indicates that the parity of the received data character does not match the
                                           parity that the EPS and SPS bits in the Line Control Register, UARTLCR_H on page 3-12 select.
                                           This bit is cleared to 0 by a write to UARTECR.
                                           In FIFO mode, this error is associated with the character at the top of the FIFO. */
#define UARTRSR_FE_SHIFT            0   /* Framing error.
                                           When set to 1, it indicates that the received character did not have a valid stop bit (a valid stop bit is 1).
                                           This bit is cleared to 0 by a write to UARTECR.
                                           In FIFO mode, this error is associated with the character at the top of the FIFO. */

/* Flag Register, UARTFR */
#define UARTFR_RI_SHIFT             8   /* Ring indicator.
                                           This bit is the complement of the UART ring indicator, nUARTRI, modem status input.
                                           That is, the bit is 1 when nUARTRI is LOW. */
#define UARTFR_TXFE_SHIFT           7   /* Transmit FIFO empty.
                                           The meaning of this bit depends on the state of the FEN bit in the Line Control Register, UARTLCR_H on page 3-12.
                                           If the FIFO is disabled, this bit is set when the transmit holding register is empty.
                                           If the FIFO is enabled, the TXFE bit is set when the transmit FIFO is empty.
                                           This bit does not indicate if there is data in the transmit shift register. */
#define UARTFR_RXFF_SHIFT           6   /* Receive FIFO full.
                                           The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register.
                                           If the FIFO is disabled, this bit is set when the receive holding register is full.
                                           If the FIFO is enabled, the RXFF bit is set when the receive FIFO is full. */
#define UARTFR_TXFF_SHIFT           5   /* Transmit FIFO full.
                                           The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register.
                                           If the FIFO is disabled, this bit is set when the transmit holding register is full.
                                           If the FIFO is enabled, the TXFF bit is set when the transmit FIFO is full. */
#define UARTFR_RXFE_SHIFT           4   /* Receive FIFO empty.
                                           The meaning of this bit depends on the state of the FEN bit in the UARTLCR_H Register.
                                           If the FIFO is disabled, this bit is set when the receive holding register is empty.
                                           If the FIFO is enabled, the RXFE bit is set when the receive FIFO is empty. */
#define UARTFR_BUSY_SHIFT           3   /* UART busy
                                           If this bit is set to 1, the UART is busy transmitting data.
                                           This bit remains set until the complete byte, including all the stop bits, has been sent from the shift register.
                                           This bit is set as soon as the transmit FIFO becomes non-empty, regardless of whether the UART is enabled or not. */
#define UARTFR_DCD_SHIFT            2   /* Data carrier detect.
                                           This bit is the complement of the UART data carrier detect, nUARTDCD, modem status input.
                                           That is, the bit is 1 when nUARTDCD is LOW. */
#define UARTFR_DSR_SHIFT            1   /* Data set ready.
                                           This bit is the complement of the UART data set ready, nUARTDSR, modem status input.
                                           That is, the bit is 1 when nUARTDSR is LOW. */
#define UARTFR_CTS_SHIFT            0   /* Clear to send.
                                           This bit is the complement of the UART clear to send, nUARTCTS, modem status input.
                                           That is, the bit is 1 when nUARTCTS is LOW. */
#define UARTFR_RI_BIT               (1 << UARTFR_RI_SHIFT)
#define UARTFR_TXFE_BIT             (1 << UARTFR_TXFE_SHIFT)
#define UARTFR_RXFF_BIT             (1 << UARTFR_RXFF_SHIFT)
#define UARTFR_TXFF_BIT             (1 << UARTFR_TXFF_SHIFT)
#define UARTFR_RXFE_BIT             (1 << UARTFR_RXFE_SHIFT)
#define UARTFR_BUSY_BIT             (1 << UARTFR_BUSY_SHIFT)
#define UARTFR_DCD_BIT              (1 << UARTFR_DCD_SHIFT)
#define UARTFR_DSR_BIT              (1 << UARTFR_DSR_SHIFT)
#define UARTFR_CTS_BIT              (1 << UARTFR_CTS_SHIFT)

/* IrDA Low-Power Counter Register, UARTILPR 
 * - 8-bit low-power divisor value
 * - low-power divisor (ILPDVSR) = (F.UARTCLK / F.IrLPBaud16)
 * - You must select the divisor so that 1.42MHz < F.IrLPBaud16 < 2.12MHz, results in a low-power pulse duration of 1.41-2.11μs (three times the period of IrLPBaud16).
 */

/* Integer Baud Rate Register, UARTIBRD
 * Fractional Baud Rate Register, UARTFBRD
 * - Baud rate divisor BAUDDIV = (F.UARTCLK/(16×Baud rate))
 * - If the required baud rate is 230400 and UARTCLK = 4MHz then:
 *   Baud Rate Divisor = (4×10^6)/(16×230400) = 1.085
 *   This means BRDI = 1 and BRDF = 0.085.
 *   Therefore, fractional part, m = integer((0.085×64)+0.5) = 5
 *   Generated baud rate divider = 1+5/64 = 1.078
 *   Generated baud rate = (4×106)/(16×1.078) = 231911
 *   Error = (231911-230400)/230400 × 100 = 0.656%
 */

/* Line Control Register, UARTLCR_H */
#define UARTIBRD_SPS_SHIFT          7   /* Stick parity select.
                                           0 = stick parity is disabled
                                           1 = either:
                                            • if the EPS bit is 0 then the parity bit is transmitted and checked as a 1
                                            • if the EPS bit is 1 then the parity bit is transmitted and checked as a 0.
                                           This bit has no effect when the PEN bit disables parity checking and generation.
                                           See Table 3-11 on page 3-14 for the parity truth table. */
#define UARTIBRD_WLEN_SHIFT         5   /* Word length.
                                           These bits indicate the number of data bits transmitted or received in a frame as follows:
                                           b11 = 8 bits
                                           b10 = 7 bits
                                           b01 = 6 bits
                                           b00 = 5 bits. */
#define     WLEN_8BIT               3
#define     WLEN_7BIT               2
#define     WLEN_6BIT               1
#define     WLEN_5BIT               0
#define UARTIBRD_FEN_SHIFT          4   /* Enable FIFOs:
                                           0 = FIFOs are disabled (character mode) that is, the FIFOs become 1-byte-deep holding registers
                                           1 = transmit and receive FIFO buffers are enabled (FIFO mode). */
#define UARTIBRD_STP2_SHIFT         3   /* Two stop bits select.
                                           If this bit is set to 1, two stop bits are transmitted at the end of the frame.
                                           The receive logic does not check for two stop bits being received. */
#define UARTIBRD_EPS_SHIFT          2   /* Even parity select.
                                           Controls the type of parity the UART uses during transmission and reception:
                                           0 = odd parity. The UART generates or checks for an odd number of 1s in the data and parity bits.
                                           1 = even parity. The UART generates or checks for an even number of 1s in the data and parity bits.
                                           This bit has no effect when the PEN bit disables parity checking and generation.
                                           See Table 3-11 on page 3-14 for the parity truth table. */
#define UARTIBRD_PEN_SHIFT          1   /* Parity enable:
                                           0 = parity is disabled and no parity bit added to the data frame
                                           1 = parity checking and generation is enabled.
                                           See Table 3-11 on page 3-14 for the parity truth table. */
#define UARTIBRD_BRK_SHIFT          0   /* Send break.
                                           If this bit is set to 1, a low-level is continually output on the UARTTXD output, after completing transmission of the current character.
                                           For the proper execution of the break command, the software must set this bit for at least two complete frames.
                                           For normal use, this bit must be cleared to 0. */

/* Control Register, UARTCR */
#define UARTCR_CTSEn_SHIFT          15  /* CTS hardware flow control enable.
                                           If this bit is set to 1, CTS hardware flow control is enabled.
                                           Data is only transmitted when the nUARTCTS signal is asserted. */
#define UARTCR_RTSEn_SHIFT          14  /* RTS hardware flow control enable.
                                           If this bit is set to 1, RTS hardware flow control is enabled.
                                           Data is only requested when there is space in the receive FIFO for it to be received. */
#define UARTCR_Out2_SHIFT           13  /* This bit is the complement of the UART Out2 (nUARTOut2) modem status output.
                                           That is, when the bit is programmed to a 1, the output is 0.
                                           For DTE this can be used as Ring Indicator (RI). */
#define UARTCR_Out1_SHIFT           12  /* This bit is the complement of the UART Out1 (nUARTOut1) modem status output.
                                           That is, when the bit is programmed to a 1 the output is 0.
                                           For DTE this can be used as Data Carrier Detect (DCD). */
#define UARTCR_RTS_SHIFT            11  /* Request to send.
                                           This bit is the complement of the UART request to send, nUARTRTS, modem status output.
                                           That is, when the bit is programmed to a 1 then nUARTRTS is LOW. */
#define UARTCR_DTR_SHIFT            10  /* Data transmit ready.
                                           This bit is the complement of the UART data transmit ready, nUARTDTR, modem status output.
                                           That is, when the bit is programmed to a 1 then nUARTDTR is LOW. */
#define UARTCR_RXE_SHIFT            9   /* Receive enable.
                                           If this bit is set to 1, the receive section of the UART is enabled.
                                           Data reception occurs for either UART signals or SIR signals depending on the setting of the SIREN bit.
                                           When the UART is disabled in the middle of reception, it completes the current character before stopping. */
#define UARTCR_TXE_SHIFT            8   /* Transmit enable.
                                           If this bit is set to 1, the transmit section of the UART is enabled.
                                           Data transmission occurs for either UART signals, or SIR signals depending on the setting of the SIREN bit. 
                                           When the UART is disabled in the middle of transmission, it completes the current character before stopping. */
#define UARTCR_LBE_SHIFT            7   /* Loopback enable.
                                           If this bit is set to 1 and the SIREN bit is set to 1 and the SIRTEST bit in the Test Control Register, UARTTCR on page 4-5 is set to 1, then the nSIROUT path is inverted, and fed through to the SIRIN path.
                                           The SIRTEST bit in the test register must be set to 1 to override the normal half-duplex SIR operation.
                                           This must be the requirement for accessing the test registers during normal operation, and SIRTEST must be cleared to 0 when loopback testing is finished.
                                           This feature reduces the amount of external coupling required during system test.
                                           If this bit is set to 1, and the SIRTEST bit is set to 0, the UARTTXD path is fed through to the UARTRXD path.
                                           In either SIR mode or UART mode, when this bit is set, the modem outputs are also fed through to the modem inputs.
                                           This bit is cleared to 0 on reset, to disable loopback. */
#define UARTCR_SIRLP_SHIFT          2   /* SIR low-power IrDA mode.
                                           This bit selects the IrDA encoding mode.
                                           If this bit is cleared to 0, low-level bits are transmitted as an active high pulse with a width of 3/16th of the bit period.
                                           If this bit is set to 1, low-level bits are transmitted with a pulse width that is 3 times the period of the IrLPBaud16 input signal, regardless of the selected bit rate.
                                           Setting this bit uses less power, but might reduce transmission distances. */
#define UARTCR_SIREN_SHIFT          1   /* SIR enable:
                                           0 = IrDA SIR ENDEC is disabled. nSIROUT remains LOW (no light pulse generated), and signal transitions on SIRIN have no effect.
                                           1 = IrDA SIR ENDEC is enabled. Data is transmitted and received on nSIROUT and SIRIN.
                                           UARTTXD remains HIGH, in the marking state.
                                           Signal transitions on UARTRXD or modem status inputs have no effect.
                                           This bit has no effect if the UARTEN bit disables the UART. */
#define UARTCR_UARTEN_SHIFT         0   /* UART enable:
                                           0 = UART is disabled. If the UART is disabled in the middle of transmission or reception, it completes the current character before stopping.
                                           1 = the UART is enabled. Data transmission and reception occurs for either UART signals or SIR signals depending on the setting of the SIREN bit. */
#define UARTCR_CTSEn_BIT            (1 << UARTCR_CTSEn_SHIFT)
#define UARTCR_RTSEn_BIT            (1 << UARTCR_RTSEn_SHIFT)
#define UARTCR_Out2_BIT             (1 << UARTCR_Out2_SHIFT)
#define UARTCR_Out1_BIT             (1 << UARTCR_Out1_SHIFT)
#define UARTCR_RTS_BIT              (1 << UARTCR_RTS_SHIFT)
#define UARTCR_DTR_BIT              (1 << UARTCR_DTR_SHIFT)
#define UARTCR_RXE_BIT              (1 << UARTCR_RXE_SHIFT)
#define UARTCR_TXE_BIT              (1 << UARTCR_TXE_SHIFT)                                   
#define UARTCR_LBE_BIT              (1 << UARTCR_LBE_SHIFT)
#define UARTCR_SIRLP_BIT            (1 << UARTCR_SIRLP_SHIFT)
#define UARTCR_SIREN_BIT            (1 << UARTCR_SIREN_SHIFT)
#define UARTCR_UARTEN_BIT           (1 << UARTCR_UARTEN_SHIFT)


/* Interrupt FIFO Level Select Register, UARTIFLS */
#define UARTIFLS_RXIFLSEL_SHIFT     3   /* Receive interrupt FIFO level select.
                                           The trigger points for the receive interrupt are as follows:
                                           b000 = Receive FIFO becomes ≥ 1/8 full
                                           b001 = Receive FIFO becomes ≥ 1/4 full
                                           b010 = Receive FIFO becomes ≥ 1/2 full
                                           b011 = Receive FIFO becomes ≥ 3/4 full
                                           b100 = Receive FIFO becomes ≥ 7/8 full
                                           b101-b111 = reserved. */
#define UARTIFLS_TXIFLSEL_SHIFT     0   /* Transmit interrupt FIFO level select.
                                           The trigger points for the transmit interrupt are as follows:
                                           b000 = Transmit FIFO becomes ≤ 1/8 full
                                           b001 = Transmit FIFO becomes ≤ 1/4 full
                                           b010 = Transmit FIFO becomes ≤ 1/2 full
                                           b011 = Transmit FIFO becomes ≤ 3/4 full
                                           b100 = Transmit FIFO becomes ≤ 7/8 full
                                           b101-b111 = reserved. */

/* Interrupt Mask Set/Clear Register, UARTIMSC 
 * Raw Interrupt Status Register, UARTRIS 
 * Masked Interrupt Status Register, UARTMIS
 * Interrupt Clear Register, UARTICR
 */
#define UARTINTR_OEI_SHIFT          10      /* Overrun error interrupt. */
#define UARTINTR_BEI_SHIFT          9       /* Break error interrupt. */
#define UARTINTR_PEI_SHIFT          8       /* Parity error interrupt. */
#define UARTINTR_FEI_SHIFT          7       /* Framing error interrupt. */
#define UARTINTR_RTI_SHIFT          6       /* Receive timeout interrupt. */
#define UARTINTR_TXI_SHIFT          5       /* Transmit interrupt. */
#define UARTINTR_RXI_SHIFT          4       /* Receive interrupt. */
#define UARTINTR_DSRMI_SHIFT        3       /* nUARTDSR modem interrupt. */
#define UARTINTR_DCDMI_SHIFT        2       /* nUARTDCD modem interrupt. */
#define UARTINTR_CTSMI_SHIFT        1       /* nUARTCTS modem interrupt. */
#define UARTINTR_RIMI_SHIFT         0       /* nUARTRI modem interrupt. */

/* DMA Control Register, UARTDMACR */
#define UARTDMACR_DMAONERR_SHIFT    2       /* DMA on error.
                                               If this bit is set to 1, the DMA receive request outputs, UARTRXDMASREQ or UARTRXDMABREQ, are disabled when the UART error interrupt is asserted. */
#define UARTDMACR_TXDMAE_SHIFT      1       /* Transmit DMA enable.
                                               If this bit is set to 1, DMA for the transmit FIFO is enabled. */
#define UARTDMACR_RXDMAE_SHIFT      0       /* Receive DMA enable.
                                               If this bit is set to 1, DMA for the receive FIFO is enabled. */

/* UARTPeriphID0 Register */
#define PL011_PartNumber0_SHIFT     0       /* These bits read back as 0x11 */

/* UARTPeriphID1 Register */
#define PL011_Designer0_SHIFT       12      /* These bits read back as 0x1 */
#define PL011_PartNumber1_SHIFT     8       /* These bits read back as 0x0 */

/* UARTPeriphID2 Register */
#define PL011_Revision_SHIFT        20      /* This field depends on the revision of the UART:
                                               r1p0     0x0
                                               r1p1     0x1
                                               r1p3     0x2
                                               r1p4     0x2
                                               r1p5     0x3 */
#define PL011_Designer1_SHIFT       16      /* These bits read back as 0x4 */

/* UARTPeriphID3 Register */
#define PL011_Configuration_SHIFT   24      /* These bits read back as 0x00 */

/* UARTPCellID0 Register */
#define PL011_UARTPCellID0_SHIFT    0       /* These bits read back as 0x0D */

/* UARTPCellID1 Register */
#define PL011_UARTPCellID1_SHIFT    8       /* These bits read back as 0xF0 */

/* UARTPCellID2 Register */
#define PL011_UARTPCellID2_SHIFT    16      /* These bits read back as 0x05 */

/* UARTPCellID3 Register */
#define PL011_UARTPCellID3_SHIFT    24      /* These bits read back as 0xB1 */

#endif  /* !PL011_REGISTER__H__ */
