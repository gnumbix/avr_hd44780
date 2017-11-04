/*
 *  HD44780 Lib for AVR
 *
 *  Copyright 2017 Kirill Pershin
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *
 *  ���������� ������ ���������� �������� ��� ����, ��� ����� WH1602B-YGK-CTK (16x2).
 *  ��� LCD �� �������� Winstar. ����������� �� ���� HD44780
 *
 *  ���� ����-�� ����� �������, ���� ����� ���.
 *
 */

// �������� � ����� ��������� ��������� LCD

// ��������� ��������.

// RS, RW, E ������ ���������� � ����� ������� � ����� ���������. �� ��� ������ ��������� �� ����� �
// ����� � ���-�� ������.

// ���� ������ ���� ������ ���������� �� ����� � ���������� ������.

// �����. ���� ������ ��������� ���������� ������ � �������� ������ ����������� 8������ �����������.
// ������ ����� ����������� ����������� ���������. PORT1 � D1, PORT2 � D2 ���...


#define HD44780_CONFIG_DATA_PORT_NAME			D	// ����� ����� � �������� ���������� ���� ������ (D0-D7)
#define HD44780_CONFIG_D0_PIN				0	// D0 (���� 4 ������ ����� �� ��������� �� �����)
#define HD44780_CONFIG_D1_PIN				1	// D1 (���� 4 ������ ����� �� ��������� �� �����)
#define HD44780_CONFIG_D2_PIN				2	// D2 (���� 4 ������ ����� �� ��������� �� �����)
#define HD44780_CONFIG_D3_PIN				3	// D3 (���� 4 ������ ����� �� ��������� �� �����)
#define HD44780_CONFIG_D4_PIN				4	// D4
#define HD44780_CONFIG_D5_PIN				5	// D5
#define HD44780_CONFIG_D6_PIN				6	// D6
#define HD44780_CONFIG_D7_PIN				7	// D7

#define HD44780_CONFIG_CONTROL_PORT_NAME		B	// ����� ����� � �������� ���������� ����������� �����
#define HD44780_CONFIG_RS_PIN				0	// RS
#define HD44780_CONFIG_RW_PIN				1	// RW
#define HD44780_CONFIG_E_PIN				2	// E

#define HD44780_CONFIG_PINMODE				1	// ���� �������� ���� ���� ���������� ���������, ���������� ��� 1
												// �� ������ ��� � ���� ������ �� ��������� ���������� ������ � ��������� ���.
												// ���� ��� �������� ���� ������ ���������� 0
												// ��� ������ 7 ������� ������ ������������ � D7 ������ � D6 ���...
												// ������������ ������������� ������������ ����� 0


// ������������� ��������� ������ �������� ��������� ��������.


#define HD44780_CONFIG_CURSOR_BLINK			1	// ������ �������� ���� �� �������  (1 ������ / 0 ���)

#define HD44780_CONFIG_CURSOR_ON			0	// ���������� ������ ��� ���. 1 ���������� / 0 ���

#define HD44780_CONFIG_CURSOR_DIRECTION			1	// ��������� ���������� ������� ���� �� ������� (1 - ������ / 0 �����)

#define HD44780_CONFIG_CURSOR_LCD_SHIFT			1	// ��������� ����� ������ ��� ������ ������� ( 1 - �� / 0 ���)

#define HD44780_CONFIG_FONT_SIZE			0	// ����� ������ ������ (1 - 5x10 / 0 - 5x8)

#define HD44780_CONFIG_BIT				1	// ����� �������� (0 - 4bit/ 1 - 8bit) 
												// 4bit ����� � �������� ��������. � ������ ��� ������. ��� ��� ����������
												// ��������� �������������� ��������.

#define HD44780_CONFIG_LINES				1	// ������� ����� ��������������. (0 - ���� / 1 - 2 � �����)

#define HD44780_CONFIG_INIT_CNT				4	// ������� ��� �������� ������� �������������.
												// ��������� ���� 4, � ��������� � 1 ������� (���������� �������� ���-��
												// ����������� ���������� ������)

#define HD44780_CONFIG_OPTIMIZATION			0	// �����������. ��� ����� �������� :
												// ���� ���������� 1 �� ����� ������ ������ ��������, �� ����� ���� ��������
												// ���� ���������� 0 �� ����� �������� ������ ������ �� ���� ������� ��������


#define HD44780_CONFIG_INITLSTART			2	// ����� ������ ��� ������ � 4bit ��� ������. � �������� �� ���������� �������������.
												// � ������ ������� �� ������� �����������.
												// 0 �������� ��� ����� ������������� ���� �� ����� (��� �� ���������)
												// 1 ����� ������������� ���� �� 2 ������� (������� ������ �� 2 �������)
												// 2 ������ ����� ��� 1 ������, � ����� �� 2

// ��������� ���� (���� ������� 0 �� ����� ��������� ������. � ��������� ������ ���������� ������)
// ��� ����� � ������������ (1ms = 1000us)
// � �������� ������ ��� ����� �� ������������. ������� ��� ��� ����� ������ ��� ������� �������� LCD
// �� ���� ��������� �� � ������� ��������� �����, �������� �����. ������� ���� ������ ������� �����. ���������� ������� ����.

#define HD44780_CONFIG_PAUSE_CMD_E				10    // ����� ����� ��������� � ���������� E ����� (����� ����� HD44780 ������� �������)

#define HD44780_CONFIG_PAUSE_AFTER_CMD				300     // ����� ����� ����� ������� (����� ���� ���������� ���� ��������� LCD)

#define HD44780_CONFIG_PAUSE_BUSY				300    // ����� ��� ������ busy �����. � ������ � ��� ���� ����� ������ ��������.

// ����� �������� ������ �� �������� �������.

#define HD44780_CONFIG_PAUSE_CMD_START				1000  // ����� ����� �������� ������. ��� ��������� LCD ��� ����������. 1ms

#define HD44780_CONFIG_PAUSE_START				40000 // ����� ����� ��������������. �� ������������ ���� 40ms

#define HD44780_CONFIG_PAUSE_WRITE_INIT				10    // ����� ����� ��������� � ���������� E ����� ��� �������������. 

#define HD44780_CONFIG_PAUSE_INIT_STEPONE			4100  // ����� ����� ������ � ������ ��������� ������������� (� ������������ 
														  // ������� ������� 4.1ms)

#define HD44780_CONFIG_PAUSE_INIT_STEPTWO			100   // ����� ����� ������ � ������� ��������� ������������� (� ������������ 
														  // ������� ������� 100us)

#define HD44780_CONFIG_PAUSE_INIT_STEPTHREE			100   // ����� ����� ������� � �������� ��������� ������������� (� ������������ 
														  // ������� ������� 100us)


/*
--------------------------------------------------------------------------------------------------------------------------
    ������ ������� �� �����       ������ ������� �� �����       ������ ������� �� �����       ������ ������� �� �����
--------------------------------------------------------------------------------------------------------------------------
*/

// ������� ��� ������ � avr ������� ���.

#define HD44780_GLUE(a, b)						a##b
#define HD44780__GLUE(a, b, c)						a##b##c
#define HD44780_PORT(x)							HD44780_GLUE(PORT, x)
#define HD44780__PORTPIN(x, y)						HD44780__GLUE(P, x , y)
#define HD44780_PIN(x)							HD44780_GLUE(PIN, x)
#define HD44780_DDR(x)							HD44780_GLUE(DDR, x)
#define HD44780__DDR_PIN(x, y)						HD44780__GLUE(DD, x, y)
#define HD44780_DDR_CONTROL_PIN(x)					HD44780__DDR_PIN(HD44780_CONFIG_CONTROL_PORT_NAME, x)
#define HD44780_DDR_DATA_PIN(x)						HD44780__DDR_PIN(HD44780_CONFIG_DATA_PORT_NAME, x)
#define HD44780_PORT_CONTROL_PIN(x)					HD44780__PORTPIN(HD44780_CONFIG_CONTROL_PORT_NAME, x)
#define HD44780_PORT_DATA_PIN(x)					HD44780__PORTPIN(HD44780_CONFIG_DATA_PORT_NAME, x)
#define HD44780_DATA_PORT_NAME						HD44780_PORT(HD44780_CONFIG_DATA_PORT_NAME)
#define HD44780_CONTROL_PORT_NAME					HD44780_PORT(HD44780_CONFIG_CONTROL_PORT_NAME)
#define HD44780_DATA_DDR_NAME						HD44780_DDR(HD44780_CONFIG_DATA_PORT_NAME)
#define HD44780_CONTROL_DDR_NAME					HD44780_DDR(HD44780_CONFIG_CONTROL_PORT_NAME)
#define HD44780_DATA_PIN_NAME						HD44780_PIN(HD44780_CONFIG_DATA_PORT_NAME)

// ���� ��� ������

#if HD44780_CONFIG_BIT > 0

	// 8Bit
	#define HD44780_SYS_DATA_DDR_PINS					(( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D0_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D1_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D2_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D3_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D4_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D5_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D6_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D7_PIN) ))
	#define HD44780_SYS_DATA_PORT_PINS					(( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D0_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D1_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D2_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D3_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D4_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D5_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D6_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D7_PIN) ))

#else

	// 4 bit
	#define HD44780_SYS_DATA_DDR_PINS					(( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D4_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D5_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D6_PIN) ) | ( 1 << HD44780_DDR_DATA_PIN(HD44780_CONFIG_D7_PIN) ))
	#define HD44780_SYS_DATA_PORT_PINS					(( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D4_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D5_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D6_PIN) ) | ( 1 << HD44780_PORT_DATA_PIN(HD44780_CONFIG_D7_PIN) ))

#endif

#define HD44780_SYS_CONTROL_DDR_PINS				(( 1 << HD44780_DDR_CONTROL_PIN(HD44780_CONFIG_RS_PIN) ) | ( 1 << HD44780_DDR_CONTROL_PIN(HD44780_CONFIG_RW_PIN) ) | ( 1 << HD44780_DDR_CONTROL_PIN(HD44780_CONFIG_E_PIN) ))
#define HD44780_SYS_CONTROL_PORT_PINS				(( 1 << HD44780_PORT_CONTROL_PIN(HD44780_CONFIG_RS_PIN) ) | ( 1 << HD44780_PORT_CONTROL_PIN(HD44780_CONFIG_RW_PIN) ) | ( 1 << HD44780_PORT_CONTROL_PIN(HD44780_CONFIG_E_PIN) ))
#define HD44780_GET_CONTROL_PORTS(rs, rw, e)		((HD44780_CONTROL_PORT_NAME & ~HD44780_SYS_CONTROL_PORT_PINS) | (( rs << HD44780_PORT_CONTROL_PIN(HD44780_CONFIG_RS_PIN) ) | ( rw << HD44780_PORT_CONTROL_PIN(HD44780_CONFIG_RW_PIN) ) | ( e << HD44780_PORT_CONTROL_PIN(HD44780_CONFIG_E_PIN) ))  )
#define HD44780_GET_CONTROL_DDRS(rs, rw, e)			((HD44780_CONTROL_DDR_NAME & ~HD44780_SYS_CONTROL_DDR_PINS) | (( rs << HD44780_DDR_CONTROL_PIN(HD44780_CONFIG_RS_PIN) ) | ( rw << HD44780_DDR_CONTROL_PIN(HD44780_CONFIG_RW_PIN) ) | ( e << HD44780_DDR_CONTROL_PIN(HD44780_CONFIG_E_PIN) ))  )
#define HD44780_SET_CONTROL_PORTS(rs, rw, e)		HD44780_CONTROL_PORT_NAME=HD44780_GET_CONTROL_PORTS(rs, rw, e)
#define HD44780_SET_CONTROL_DDRS(rs, rw, e)			HD44780_CONTROL_DDR_NAME=HD44780_GET_CONTROL_DDRS(rs, rw, e)
#define HD44780_SET_DATA_PORTS_NULL					HD44780_DATA_PORT_NAME=((HD44780_DATA_PORT_NAME & ~HD44780_SYS_DATA_PORT_PINS) ) // | HD44780_SYS_DATA_PORT_PINS)
#define HD44780_SET_DATA_PORTS_WRITE				HD44780_DATA_DDR_NAME=((HD44780_DATA_DDR_NAME & ~HD44780_SYS_DATA_DDR_PINS) | HD44780_SYS_DATA_DDR_PINS)
#define HD44780_SET_DATA_PORTS_READ					HD44780_DATA_DDR_NAME=(HD44780_DATA_DDR_NAME & ~HD44780_SYS_DATA_DDR_PINS)

// ���������� � ��������� HD44780


// ������� ������ � ��������� ��������� �������� DDRAM � 0
// 1ms
#define HD44780_INSTRUCTION_CLEAR					0x01	

// ������������� �������� ������� DDRAM � 0. ������ �����, ���������� ����� � ������������ ����������.
// ���� �� ��� �������. ���������� DDRAM �������� ����������.
// 1.52ms
#define HD44780_INSTRUCTION_HOME					0x02	

// ��������� ���������� ����������� �������� �������(DB1) � ���������/��������� ����� ������(DB0)
// 37 us
#define HD44780_INSTRUCTION_ENTRY_MODE				0x04

// ���������� �������. �������/�������� (DB2) , ���������� ������ ��� ��� (DB1), ������ �������� ��� ��� (DB0)
// 37 us
#define HD44780_INSTRUCTION_LCD_CTRL				0x08

// ������� ������ � �������� ����� ��� ��������� ����������� DDRAM (DB3 ��� / DB2 �����������)
// 37 us
#define HD44780_INSTRUCTION_SHIFT					0x10

// ������� �������������. ������������ ��� ����� �������. ����� ��� �� ��������.
// ��� ���-�� ������������� �������� (DB4 1=8bit/0=4bit)
// ���������� ����� �� ������ (DB3 1=2������/0=1������)
// ������ ������ (DB2 1=5x10 / 0=5x8)
// 37 us
#define HD44780_INSTRUCTION_FUNCTION_SET			0x20

// ������������� CGRAM �����. ����� �������(����/��������) ���������� ����� ����� ���� �������.
// � DB0-DB5 �����.
// 37 us
#define HD44780_INSTRUCTION_CGRAM_ADDRESS			0x40

// ������������� DDRAM �����. ����� �������(����/��������) ���������� ����� ����� ���� �������.
// � DB0-DB6 �����.
// 37 us
#define HD44780_INSTRUCTION_DDRAM_ADDRESS			0x80


// ����� (���������� ��� ������ ������ ��������) HD44780


// ���� ���������� LCD.(���������-�� �� ������� ��� ��� ���) ���-�� ������������ ������ �� ���������� ��������� ��������.
// ���������� ������ � RW
// 0 us
#define HD44780_FLAG_BUSY							0x80   //(1<<HD44780_CONFIG_D7_PIN) // 0x80

// ����������� ������� ������
#define HD44780_FLAG_CURSOR_DIRECTION				0x02

// ��������� ����� ������ �� ������� �������
#define HD44780_FLAG_DISPLAY_SHIFT					0x01

// ��������� ������
#define HD44780_FLAG_DISPLAY_ACTIVE					0x04

// ��������� ����� ������� �� ������
#define HD44780_FLAG_CURSOR_ACTIVE					0x02

// �������� �����
#define HD44780_FLAG_CURSOR_BLINK					0x01

// ����� ������
#define HD44780_FLAG_SHIFT_DISPLAY					0x08

// �������� ������ ��� ������� ������
#define HD44780_FLAG_SHIFT_DIRECTION				0x04

// ��������� 8 ������� ������
#define HD44780_FLAG_EIGHT_BIT						0x10

// ��������� ���� � ����� ��������� ������
#define HD44780_FLAG_TWO_LINES						0x08

// ������ ������ 5x10
#define HD44780_FLAG_FONT_SIZE						0x04


// ������ ������� ��� ������� ��������� �����


#if HD44780_CONFIG_OPTIMIZATION>0
#define HD44780_INIT_SEND_OPT(a)					hd44780_send_command(a,0,0)
#define HD44780_CMD_SEND_OPT(a,b)					hd44780_send_command(a,b,1)
#else
#define HD44780_INIT_SEND_OPT(a)					hd44780_send_nibble(a)
#define HD44780_CMD_SEND_OPT(a,b)					hd44780_send_command(a,b)
#endif


// ��������� �������� �������
// ����������� �������� ������� (direction 0 ����� / 1 ������ )
// ����� ������ ��� ����������� ������� (displayshift 0 ��������� / 1 ���������)
#define HD44780_SET_ENTRY_MODE(direction, displayshift)		( HD44780_INSTRUCTION_ENTRY_MODE | (direction ? HD44780_FLAG_CURSOR_DIRECTION : 0) | (displayshift ? 0 : HD44780_FLAG_DISPLAY_SHIFT) )

// ��������� ������ ������
// ��������� ������ (active  0 �������� / 1 �������)
// ���������� ��� ��� ������ (cursor 0 ������ / 1 ����������)
// ������ �������� ( 0 ��� / 1 ��)  ���� cursor ����������� � 0 �� ������� ���� �����������
#define HD44780_SET_LCD_CTRL(active, cursor, blink)		( HD44780_INSTRUCTION_LCD_CTRL | (active ? HD44780_FLAG_DISPLAY_ACTIVE : 0) | (cursor ? HD44780_FLAG_CURSOR_ACTIVE : 0) | (blink ? ( cursor ? HD44780_FLAG_CURSOR_BLINK : 0 ) : 0) )

// ��������� ������� ����� ��� ������
// ��������� ��� ������� (what 0 ������� ������ / 1 ������� �����)
// � ����� ����������� ������� (direction 0 ����� / 1 ������)
#define HD44780_SET_SHIFT(what, direction)			( HD44780_INSTRUCTION_SHIFT | (what ? HD44780_FLAG_SHIFT_DISPLAY : 0) | (direction ? HD44780_FLAG_SHIFT_DIRECTION : 0) )

// ������������ ��� �������������. ������������� ����� ��������, ���������� ����� � ������ ������.
// ����� ������������� �������� ������.
// ����� �������� (bitmode 0 = 4bit / 1 = 8bit)
// ���������� ����� (lines 0 = 1 ������ / 1 = 2 � �����)
// ������ ������ (fontsize 0 = 5x8 / 1 = 5x10)
#define HD44780_SET_FUNCTION(bitmode, lines, fontsize)		( HD44780_INSTRUCTION_FUNCTION_SET | ( bitmode ? HD44780_FLAG_EIGHT_BIT : 0 ) | ( lines ? HD44780_FLAG_TWO_LINES : 0 ) | ( fontsize ? HD44780_FLAG_FONT_SIZE : 0 ) )
#define HD44780_SET_FUNCTIONEX(bitmode, lines, fontsize)		( HD44780_INSTRUCTION_FUNCTION_SET | ( bitmode ? HD44780_FLAG_EIGHT_BIT : 0 ) | ( fontsize ? HD44780_FLAG_FONT_SIZE : 0 ) )

// ������������� ����� CGRAM. � addr ����� ������� ����� ����������.
#define HD44780_SET_CGRAM_ADDRESS(addr)				(HD44780_INSTRUCTION_CGRAM_ADDRESS | addr )

// ������������� ����� DDRAM. � addr ����� ������� ����� ����������.
#define HD44780_SET_DDRAM_ADDRESS(addr)				(HD44780_INSTRUCTION_DDRAM_ADDRESS | addr )

// ������������ ������� �������
#define	HD44780_GET_CURSOR_POS(x, y)				(x*0x40+y)


//	������� ��� �������.


// ���������� ��������� �������� �������
// ����������� �������� ������� (direction 0 ����� / 1 ������ )
// ����� ������ ��� ����������� ������� (displayshift 0 ��������� / 1 ���������)
#define HD44780_SEND_ENTRY_MODE(direction, displayshift)		HD44780_CMD_SEND_OPT(HD44780_SET_ENTRY_MODE(direction, displayshift), 0)

// ���������� ��������� ������ ������
// ��������� ������ (active  0 �������� / 1 �������)
// ���������� ��� ��� ������ (cursor 0 ������ / 1 ����������)
// ������ �������� ( 0 ��� / 1 ��)  ���� cursor ����������� � 0 �� ������� ���� �����������
#define HD44780_SEND_LCD_CTRL(active, cursor, blink)		HD44780_CMD_SEND_OPT(HD44780_SET_LCD_CTRL(active, cursor, blink), 0)

// ���������� ������� ����������� ������ ��� �������
// ��������� ��� ������� (what 0 ������� ������ / 1 ������� �����)
// � ����� ����������� ������� (direction 0 ����� / 1 ������)
#define HD44780_SEND_SHIFT(what, direction)			HD44780_CMD_SEND_OPT(HD44780_SET_SHIFT(what, direction), 0)

// ���������� ����� ��������, ���������� ����� � ������ ������.
// ����� ������������� �������� ������.
// ����� �������� (bitmode 0 = 4bit / 1 = 8bit)
// ���������� ����� (lines 0 = 1 ������ / 1 = 2 � �����)
// ������ ������ (fontsize 0 = 5x8 / 1 = 5x10)
#define HD44780_SEND_FUNCTION(bitmode, lines, fontsize)		HD44780_INIT_SEND_OPT(HD44780_SET_FUNCTION(bitmode, lines, fontsize))

//#if HD44780_CONFIG_BIT==0 && HD44780_CONFIG_INITLSTART==2
//#define HD44780_SEND_FUNCTIONEX(bitmode, lines, fontsize)		hd44780_send_nibbleex(HD44780_SET_FUNCTION(bitmode, lines, fontsize))
//#endif

// ������������� ����� CGRAM. � addr ����� ������� ����� ����������.
#define HD44780_SEND_CGRAM_ADDRESS(addr)			HD44780_CMD_SEND_OPT(HD44780_SET_CGRAM_ADDRESS(addr) ,0)

// ������������� ����� DDRAM. � addr ����� ������� ����� ����������.
#define HD44780_SEND_DDRAM_ADDRESS(addr)			HD44780_CMD_SEND_OPT(HD44780_SET_DDRAM_ADDRESS(addr) ,0)

// ������� ������
#define HD44780_SEND_SHIFT_CURSOR(direction)		HD44780_SEND_SHIFT(0, direction)
#define HD44780_SEND_CURSOR_LEFT					HD44780_SEND_SHIFT_CURSOR(0)
#define HD44780_SEND_CURSOR_RIGHT					HD44780_SEND_SHIFT_CURSOR(1)

// ������� �����
#define HD44780_SEND_SHIFT_DISPLAY(direction)		HD44780_SEND_SHIFT(1, direction)
#define HD44780_SEND_DISPLAY_LEFT					HD44780_SEND_SHIFT_DISPLAY(0)
#define HD44780_SEND_DISPLAY_RIGHT					HD44780_SEND_SHIFT_DISPLAY(1)

// 
#define HD44780_SEND_CMD_HOME						HD44780_CMD_SEND_OPT(HD44780_INSTRUCTION_HOME,0)

// ������� ������
#define HD44780_SEND_CMD_CLEAR						HD44780_CMD_SEND_OPT(HD44780_INSTRUCTION_CLEAR,0)

// �������� �������
#define HD44780_SEND_CHAR(a)						HD44780_CMD_SEND_OPT(a,1)

// ������������� ������ �� ����������� x, y
#define HD44780_SEND_CURSOR_POS(x, y)				HD44780_CMD_SEND_OPT(HD44780_SET_DDRAM_ADDRESS(HD44780_GET_CURSOR_POS(x, y)),0)


// ���������� �������� �������
#include <avr/io.h>
#include <util/delay.h>

// �������

#if HD44780_CONFIG_PINMODE>0
	uint8_t hd44780_pin_convert_to(uint8_t);
	uint8_t hd44780_pin_convert_from(uint8_t);
#endif

uint8_t hd44780_ready();

#if HD44780_CONFIG_OPTIMIZATION<=0
	void hd44780_send_nibble(uint8_t);
#endif


#if HD44780_CONFIG_OPTIMIZATION>0
	void hd44780_send_command(uint8_t,uint8_t,uint8_t);
#else
	void hd44780_send_command(uint8_t,uint8_t);
#endif

void hd44780_init(void);

