/*
 *  TOPPERS/HRP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 * 
 *  Copyright (C) 2015 by Ushio Laboratory
 *              Graduate School of Engineering Science, Osaka Univ., JAPAN
 *  Copyright (C) 2015 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  $Id: tDataqueue_inline.h 285 2018-03-21 02:55:49Z ertl-hiro $
 */

#ifndef TOPPERS_TDATAQUEUE_INLINE_H
#define TOPPERS_TDATAQUEUE_INLINE_H

/*
 *  データキューへの送信
 */
Inline ER
eDataqueue_send(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(snd_dtq(ATTR_id, data));
}

/*
 *  データキューへの送信（ポーリング）
 */
Inline ER
eDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(psnd_dtq(ATTR_id, data));
}

/*
 *  データキューへの送信（タイムアウトあり）
 */
Inline ER
eDataqueue_sendTimeout(CELLIDX idx, intptr_t data, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(tsnd_dtq(ATTR_id, data, timeout));
}

/*
 *  データキューへの強制送信
 */
Inline ER
eDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(fsnd_dtq(ATTR_id, data));
}

/*
 *  データキューからの受信
 */
Inline ER
eDataqueue_receive(CELLIDX idx, intptr_t* p_data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	ID		task_id;
	(void)get_tid( &task_id );

	// syslog( LOG_INFO, "tDataqueue.eDataqueue.receive id=%d p_cellcb=%08x task_id=%d", ATTR_id, (intptr_t)p_cellcb,task_id);
	return(rcv_dtq(ATTR_id, p_data));
}

/*
 *  データキューからの受信（ポーリング）
 */
Inline ER
eDataqueue_receivePolling(CELLIDX idx, intptr_t* p_data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(prcv_dtq(ATTR_id, p_data));
}

/*
 *  データキューからの受信（タイムアウトあり）
 */
Inline ER
eDataqueue_receiveTimeout(CELLIDX idx, intptr_t* p_data, TMO timeout)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(trcv_dtq(ATTR_id, p_data, timeout));
}

/*
 *  データキューの再初期化
 */
Inline ER
eDataqueue_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ini_dtq(ATTR_id));
}

/*
 *  データキューの状態参照
 */
Inline ER
eDataqueue_refer(CELLIDX idx, T_RDTQ* pk_dataqueueStatus)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(ref_dtq(ATTR_id, pk_dataqueueStatus));
}

/*
 *  データキューへの送信（ポーリング，非タスクコンテキスト用）
 */
Inline ER
eiDataqueue_sendPolling(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(psnd_dtq(ATTR_id, data));
}

/*
 *  データキューへの強制送信（非タスクコンテキスト用）
 */
Inline ER
eiDataqueue_sendForce(CELLIDX idx, intptr_t data)
{
	CELLCB	*p_cellcb = GET_CELLCB(idx);
	return(fsnd_dtq(ATTR_id,  data));
}

#endif /* TOPPERS_TDATAQUEUE_INLINE_H */
