/*
 * This file was automatically generated by tecsgen.
 * Move and rename like below before editing,
 *   gen/tExc08_templ.c => src/tExc08.c
 * to avoid to be overwritten by tecsgen.
 */
/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * attr access macro #_CAAM_#
 * sampleNo         int              ATTR_sampleNo   
 * taskName         char**           ATTR_taskName   
 *
 * call port function #_TCPF_#
 * require port: signature:sKernel context:task
 *   ER             getExtendedInformation( intptr_t* p_exinf );
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delayTime );
 *   ER             exit( );
 *   ER             disableTerminate( );
 *   ER             enableTerminate( );
 *   bool_t         senseTerminate( );
 *   ER             setTime( SYSTIM systemTime );
 *   ER             getTime( SYSTIM* p_systemTime );
 *   ER             adjustTime( int32_t adjustTime );
 *   HRTCNT         fetchHighResolutionTimer( );
 *   ER             rotateReadyQueue( PRI taskPriority );
 *   ER             multiRotateReadyQueue( ID domainId, PRI taskPriority );
 *   ER             getTaskId( ID* p_taskId );
 *   ER             getLoad( PRI taskPriority, uint_t* p_load );
 *   ER             multiGetLoad( ID domainId, PRI taskPriority, uint_t* p_load );
 *   ER             getNthTask( PRI taskPriority, uint_t nth, ID* p_taskID );
 *   ER             multiGetNthTask( ID domainId, PRI taskPriority, uint_t nth, ID* p_taskID );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 *   ER             exitKernel( );
 *   ER             changeInterruptPriorityMask( PRI interruptPriority );
 *   ER             getInterruptPriorityMask( PRI* p_interruptPriority );
 *   ER             getProcessorID( ID* p_prcid );
 * require port: signature:siKernel context:non-task
 *   HRTCNT         ciKernel_fetchHighResolutionTimer( );
 *   ER             ciKernel_rotateReadyQueue( PRI taskPriority );
 *   ER             ciKernel_multiRotateReadyQueue( ID domainId, PRI taskPriority );
 *   ER             ciKernel_getTaskId( ID* p_taskId );
 *   ER             ciKernel_lockCpu( );
 *   ER             ciKernel_unlockCpu( );
 *   bool_t         ciKernel_senseContext( );
 *   bool_t         ciKernel_senseLock( );
 *   bool_t         ciKernel_senseDispatch( );
 *   bool_t         ciKernel_senseDispatchPendingState( );
 *   bool_t         ciKernel_senseKernel( );
 *   ER             ciKernel_exitKernel( );
 *   bool_t         ciKernel_exceptionSenseDispatchPendingState( const void* p_exceptionInformation );
 * call port: cTask signature: sTask context:task
 *   ER             cTask_activate( subscript );
 *   ER             cTask_migrateAndActivate( subscript, ID prcid );
 *   ER_UINT        cTask_cancelActivate( subscript );
 *   ER             cTask_migrate( subscript, ID prcid );
 *   ER             cTask_getTaskState( subscript, STAT* p_tskstat );
 *   ER             cTask_changePriority( subscript, PRI priority );
 *   ER             cTask_changeSubPriority( subscript, uint_t subPriority );
 *   ER             cTask_getPriority( subscript, PRI* p_priority );
 *   ER             cTask_refer( subscript, T_RTSK* pk_taskStatus );
 *   ER             cTask_wakeup( subscript );
 *   ER_UINT        cTask_cancelWakeup( subscript );
 *   ER             cTask_releaseWait( subscript );
 *   ER             cTask_suspend( subscript );
 *   ER             cTask_resume( subscript );
 *   ER             cTask_raiseTerminate( subscript );
 *   ER             cTask_terminate( subscript );
 *       subscript:  0...(NCP_cTask-1)
 * call port: cCyclic signature: sCyclic context:task
 *   ER             cCyclic_start( );
 *   ER             cCyclic_stop( );
 *   ER             cCyclic_refer( T_RCYC* pk_cyclicHandlerStatus );
 * call port: cAlarm signature: sAlarm context:task
 *   ER             cAlarm_start( RELTIM alarmTime );
 *   ER             cAlarm_stop( );
 *   ER             cAlarm_refer( T_RALM* pk_alarmStatus );
 * call port: cSerialPort signature: sSerialPort context:task
 *   ER             cSerialPort_open( );
 *   ER             cSerialPort_close( );
 *   ER_UINT        cSerialPort_read( char* buffer, uint_t length );
 *   ER_UINT        cSerialPort_write( const char* buffer, uint_t length );
 *   ER             cSerialPort_control( uint_t ioControl );
 *   ER             cSerialPort_refer( T_SERIAL_RPOR* pk_rpor );
 * call port: cSysLog signature: sSysLog context:task
 *   ER             cSysLog_write( uint_t priority, const SYSLOG* p_syslog );
 *   ER_UINT        cSysLog_read( SYSLOG* p_syslog );
 *   ER             cSysLog_mask( uint_t logMask, uint_t lowMask );
 *   ER             cSysLog_refer( T_SYSLOG_RLOG* pk_rlog );
 *   ER             cSysLog_flush( );
 * call port: cService signature: sService context:task
 *   ER             cService_migrate( int_t no );
 *   ER             cService_terminate( int_t no );
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "tExc08_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eMainTask
 * entry port: eMainTask
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMainTask_main
 * name:         eMainTask_main
 * global_name:  tExc08_eMainTask_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eMainTask_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eSampleTask
 * entry port: eSampleTask
 * signature:  sTaskBody
 * context:    task
 * entry port array size:  NEP_eSampleTask
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSampleTask_main
 * name:         eSampleTask_main
 * global_name:  tExc08_eSampleTask_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eSampleTask_main(CELLIDX idx, int_t subscript)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eService
 * entry port: eService
 * signature:  sService
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eService_migrate
 * name:         eService_migrate
 * global_name:  tExc08_eService_migrate
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eService_migrate(CELLIDX idx, int_t no)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Oneway function always returns E_OK. */
		return(E_OK);
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

	/* Oneway function always returns E_OK. */
	return(E_OK);
}

/* #[<ENTRY_FUNC>]# eService_terminate
 * name:         eService_terminate
 * global_name:  tExc08_eService_terminate
 * oneway:       true
 * #[</ENTRY_FUNC>]# */
ER
eService_terminate(CELLIDX idx, int_t no)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Oneway function always returns E_OK. */
		return(E_OK);
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

	/* Oneway function always returns E_OK. */
	return(E_OK);
}

/* #[<ENTRY_PORT>]# eiCyclicHandler
 * entry port: eiCyclicHandler
 * signature:  siHandlerBody
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiCyclicHandler_main
 * name:         eiCyclicHandler_main
 * global_name:  tExc08_eiCyclicHandler_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiCyclicHandler_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eiAlarmHandler
 * entry port: eiAlarmHandler
 * signature:  siHandlerBody
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiAlarmHandler_main
 * name:         eiAlarmHandler_main
 * global_name:  tExc08_eiAlarmHandler_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiAlarmHandler_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/
