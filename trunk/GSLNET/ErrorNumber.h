/* ErrorNumber.h
 * 
 * Copyright (C) 2008 E.Togashi
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#pragma once

namespace GSLNET {

///<summary>GSLNETエラーコード</summary>
public enum class ErrorNumber { 
	///<summary>成功</summary>
	GSL_SUCCESS  = 0, 
	///<summary>失敗</summary>
	GSL_FAILURE  = -1,
	///<summary>iteration has not converged</summary>
	GSL_CONTINUE = -2,
	///<summary>input domain error, e.g sqrt(-1)</summary>
	GSL_EDOM     = 1, 
	///<summary>output range error, e.g. exp(1e100)</summary>
	GSL_ERANGE   = 2,
	///<summary>invalid pointer</summary>
	GSL_EFAULT   = 3,
	///<summary>invalid argument supplied by user</summary>
	GSL_EINVAL   = 4,
	///<summary>generic failure</summary>
	GSL_EFAILED  = 5,
	///<summary>factorization failed</summary>
	GSL_EFACTOR  = 6,
	///<summary>sanity check failed - shouldn't happen</summary>
	GSL_ESANITY  = 7,
	///<summary>malloc failed</summary>
	GSL_ENOMEM   = 8,
	///<summary>problem with user-supplied function</summary>
	GSL_EBADFUNC = 9,
	///<summary>iterative process is out of control</summary>
	GSL_ERUNAWAY = 10,
	///<summary>exceeded max number of iterations</summary>
	GSL_EMAXITER = 11,
	///<summary>tried to divide by zero</summary>
	GSL_EZERODIV = 12,
	///<summary>user specified an invalid tolerance</summary>
	GSL_EBADTOL  = 13,
	///<summary>failed to reach the specified tolerance</summary>
	GSL_ETOL     = 14,
	///<summary>underflow</summary>
	GSL_EUNDRFLW = 15,
	///<summary>overflow</summary>
	GSL_EOVRFLW  = 16,
	///<summary>loss of accuracy</summary>
	GSL_ELOSS    = 17,
	///<summary>failed because of roundoff error</summary>
	GSL_EROUND   = 18,
	///<summary>matrix, vector lengths are not conformant</summary>
	GSL_EBADLEN  = 19,
	///<summary>matrix not square</summary>
	GSL_ENOTSQR  = 20,
	///<summary>apparent singularity detected</summary>
	GSL_ESING    = 21,
	///<summary>integral or series is divergent</summary>
	GSL_EDIVERGE = 22,
	///<summary>requested feature is not supported by the hardware</summary>
	GSL_EUNSUP   = 23,
	///<summary>requested feature not (yet) implemented</summary>
	GSL_EUNIMPL  = 24,
	///<summary>cache limit exceeded</summary>
	GSL_ECACHE   = 25,
	///<summary>table limit exceeded</summary>
	GSL_ETABLE   = 26,
	///<summary>iteration is not making progress towards solution</summary>
	GSL_ENOPROG  = 27,
	///<summary>jacobian evaluations are not improving the solution</summary>
	GSL_ENOPROGJ = 28,
	///<summary>cannot reach the specified tolerance in F</summary>
	GSL_ETOLF    = 29,
	///<summary>cannot reach the specified tolerance in X</summary>
	GSL_ETOLX    = 30,
	///<summary>cannot reach the specified tolerance in gradient</summary>
	GSL_ETOLG    = 31,
	///<summary>end of file</summary>
	GSL_EOF      = 32
} ;


}