// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once 

namespace ServiceModel
{
    class ServiceNameQueryResult 
        : public Serialization::FabricSerializable
    {
    public:
        ServiceNameQueryResult();
        ServiceNameQueryResult(Common::Uri const & serviceName);
        ServiceNameQueryResult(ServiceNameQueryResult const & other);
        ServiceNameQueryResult(ServiceNameQueryResult && other);

        __declspec(property(get=get_ServiceName)) Common::Uri const & ServiceName;
        Common::Uri const & get_ServiceName() const { return serviceName_; }

        ServiceNameQueryResult const & operator = (ServiceNameQueryResult const & other);
        ServiceNameQueryResult const & operator = (ServiceNameQueryResult && other);

        void ToPublicApi(
            __in Common::ScopedHeap & heap, 
            __out FABRIC_SERVICE_NAME_QUERY_RESULT & publicQueryResult) const;

        Common::ErrorCode FromPublicApi(__in FABRIC_SERVICE_NAME_QUERY_RESULT const& publicQueryResult);

        void WriteTo(Common::TextWriter&, Common::FormatOptions const &) const;
        std::wstring ToString() const;

        FABRIC_FIELDS_01(serviceName_)

        BEGIN_JSON_SERIALIZABLE_PROPERTIES()
            SERIALIZABLE_PROPERTY(Constants::Name, serviceName_)
        END_JSON_SERIALIZABLE_PROPERTIES()

    private:
        Common::Uri serviceName_;
    };
}
