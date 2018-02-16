/**
 *******************************************************************************
 *******************************************************************************
 *
 * @file	spitest.c
 * @author	R. Bush
 * @email	bush@krtkl.com
 * @version	v1.0
 * @date	2016 September 10
 * @brief	SPI Bridge Testing
 * @license	FreeBSD
 *
 *******************************************************************************
 *
 * Copyright (c) 2016, krtkl inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *	  and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVICED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the FreeBSD Project.
 *
 *******************************************************************************
 */

/*---------------------------------- Includes --------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>



int
main (int argc, char *argv[])
{
	int i, fid, status, len;
	struct spi_ioc_transfer xfer;
	unsigned char rx_buf[5];
	unsigned char tx_buf[5];
	unsigned char out_buf[128];
	unsigned int tx_val;
	char *name = argv[1];			/* device file is the first argument */
	int xfer_len = argc - 2;

	printf("Opening SPIDev: %s\n", name);
	fid = open(name, O_RDWR);

	memset(tx_buf, 0, sizeof(tx_buf));
	memset(rx_buf, 0, sizeof(rx_buf));
	memset(&xfer, 0, sizeof(struct spi_ioc_transfer));

	for (i = 0; i < xfer_len; i++) {
		sscanf(argv[i + 2], "%x", (unsigned int *)&tx_buf[i]);
	}

	if (fid < 0) {
		perror("Opening file");
		return 1;
	}

	xfer.tx_buf = (unsigned long)tx_buf;
	xfer.rx_buf = (unsigned long)rx_buf;
	xfer.speed_hz = 500000;
	xfer.len = xfer_len;

	status = ioctl(fid, SPI_IOC_MESSAGE(1), &xfer);

	len = sprintf(out_buf, "MOSI: ");
	for (i = 0; i < xfer_len; i++) {
		len += sprintf(&out_buf[len], "0x%02X ", tx_buf[i]);
	}

	len += sprintf(&out_buf[len], "\nMISO: ");
	for (i = 0; i < xfer_len; i++) {
		len += sprintf(&out_buf[len], "0x%02X ", rx_buf[i]);
	}

	printf("%s\n", out_buf);
}
