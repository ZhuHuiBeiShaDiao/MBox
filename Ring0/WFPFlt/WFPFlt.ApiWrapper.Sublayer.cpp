#include "stdafx.h"
#include "WFPFlt.ApiWrapper.Sublayer.h"
#include <ShimsApi\ShimsApi.WFP.Sublayer.h>

namespace MBox
{
    namespace WFPFlt
    {
        namespace WFPApiWrapper
        {
            NTSTATUS SublayerAdd(SublayerAddParameter * aParameter)
            {
                FWPM_SUBLAYER0 vSublayer0 = { 0 };

                return ShimsApi::WFP::FwpmSubLayerAdd0Shims(
                    aParameter->m_EngineHandle,
                    WFPFltSublayerToSublayer(&vSublayer0, aParameter->m_Sublayer),
                    aParameter->m_SecurityDescriptor);
            }
            NTSTATUS SublayerDeleteByKey(SublayerDeleteByKeyParameter * aParameter)
            {
                return ShimsApi::WFP::FwpmSubLayerDeleteByKey0Shims(aParameter->m_EngineHandle, aParameter->m_SublayerGuid);
            }
        }
    }
}
