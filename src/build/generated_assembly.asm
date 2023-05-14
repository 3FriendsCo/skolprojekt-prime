; ----------------------------------------------------------------------------------|
; Assembly version: x86_64 (AMD_64)                                                 |
;                                                                                   |
; Copyright (c) 2023, 3FriendsCo                                                    |
; Authors: Pontus Henriksson & Neo Mannskär                                         |
;                                                                                   |
; Licensed under the MIT License. You may not use this file except in compliance    |
; with the License. You may obtain a copy of the License at:                        |
;                                                                                   |
; - https://opensource.org/licenses/MIT                                             |
;                                                                                   |
; ----------------------------------------------------------------------------------|

include 'INCLUDE/win64ax.inc' ; you can simply switch between win32ax, win32wx, win64ax and win64wx here

.code

  start:

	invoke	MessageBox,HWND_DESKTOP,"May I introduce myself?",invoke GetCommandLine,MB_YESNO

	.if eax = IDYES
		invoke	MessageBox,HWND_DESKTOP,"Hi! I'm the example program!","Hello!",MB_OK
	.endif

	invoke	ExitProcess,0

.end start
