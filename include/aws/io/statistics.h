#ifndef AWS_IO_STATISTICS_H
#define AWS_IO_STATISTICS_H

/*
 * Copyright 2010-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <aws/io/io.h>

#include <aws/common/statistics.h>

enum aws_crt_io_statistics_category {
    AWSCRT_STAT_CAT_SOCKET = AWS_CRT_STATISTICS_CATEGORY_BEGIN_RANGE(AWS_C_IO_PACKAGE_ID),
    AWSCRT_STAT_CAT_TLS
};

struct aws_crt_statistics_socket {
    aws_crt_statistics_category_t category;
    uint64_t bytes_read;
    uint64_t bytes_written;
};

enum aws_tls_negotiation_status {
    AWS_MTLS_STATUS_NONE,
    AWS_MTLS_STATUS_ONGOING,
    AWS_MTLS_STATUS_SUCCESS,
    AWS_MTLS_STATUS_FAILURE
};

struct aws_crt_statistics_tls {
    aws_crt_statistics_category_t category;
    uint64_t handshake_start_ms;
    enum aws_tls_negotiation_status handshake_status;
};

AWS_EXTERN_C_BEGIN

AWS_IO_API
int aws_crt_statistics_socket_init(struct aws_crt_statistics_socket *stats);

AWS_IO_API
void aws_crt_statistics_socket_cleanup(struct aws_crt_statistics_socket *stats);

AWS_IO_API
void aws_crt_statistics_socket_reset(struct aws_crt_statistics_socket *stats);

AWS_IO_API
int aws_crt_statistics_tls_init(struct aws_crt_statistics_tls *stats);

AWS_IO_API
void aws_crt_statistics_tls_cleanup(struct aws_crt_statistics_tls *stats);

AWS_IO_API
void aws_crt_statistics_tls_reset(struct aws_crt_statistics_tls *stats);

AWS_EXTERN_C_END

#endif /* AWS_IO_STATISTICS_H */