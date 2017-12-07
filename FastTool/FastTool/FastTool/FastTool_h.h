

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for FastTool.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __FastTool_h_h__
#define __FastTool_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFastTool_FWD_DEFINED__
#define __IFastTool_FWD_DEFINED__
typedef interface IFastTool IFastTool;

#endif 	/* __IFastTool_FWD_DEFINED__ */


#ifndef __FastTool_FWD_DEFINED__
#define __FastTool_FWD_DEFINED__

#ifdef __cplusplus
typedef class FastTool FastTool;
#else
typedef struct FastTool FastTool;
#endif /* __cplusplus */

#endif 	/* __FastTool_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __FastTool_LIBRARY_DEFINED__
#define __FastTool_LIBRARY_DEFINED__

/* library FastTool */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_FastTool;

#ifndef __IFastTool_DISPINTERFACE_DEFINED__
#define __IFastTool_DISPINTERFACE_DEFINED__

/* dispinterface IFastTool */
/* [uuid] */ 


EXTERN_C const IID DIID_IFastTool;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("fbdd846e-f10e-4be0-ba72-2b6cef4f67a8")
    IFastTool : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFastToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFastTool * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFastTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFastTool * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFastTool * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFastTool * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFastTool * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFastTool * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IFastToolVtbl;

    interface IFastTool
    {
        CONST_VTBL struct IFastToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFastTool_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFastTool_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFastTool_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFastTool_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFastTool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFastTool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFastTool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFastTool_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FastTool;

#ifdef __cplusplus

class DECLSPEC_UUID("4e828ecd-c582-4a7d-8cd0-258c2efa56bd")
FastTool;
#endif
#endif /* __FastTool_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


