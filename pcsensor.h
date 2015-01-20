/*
 * pcsensor.c by Michitaka Ohno (c) 2011 (elpeo@mars.dti.ne.jp)
 * based oc pcsensor.c by Juan Carlos Perez (c) 2011 (cray@isp-sl.com)
 * based on Temper.c by Robert Kavaler (c) 2009 (relavak.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY Juan Carlos Perez ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Robert kavaler BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <usb.h>
#include <stdio.h>

#include <string.h>
#include <errno.h>
#include <float.h>

/*
static int device_type(usb_dev_handle *lvr_winusb);

static int usb_detach(usb_dev_handle *lvr_winusb, int iInterface);

static usb_dev_handle *find_lvr_winusb();

static usb_dev_handle* setup_libusb_access();

static int ini_control_transfer(usb_dev_handle *dev);

static int control_transfer(usb_dev_handle *dev, const char *pquestion);

static int interrupt_read(usb_dev_handle *dev);

static int interrupt_read_temperatura(usb_dev_handle *dev, float *tempC);

static int get_data(usb_dev_handle *dev, char *buf, int len);

static int get_temperature(usb_dev_handle *dev, float *tempC);

*/

usb_dev_handle* pcsensor_open();

void pcsensor_close(usb_dev_handle* lvr_winusb);

float pcsensor_get_temperature(usb_dev_handle* lvr_winusb);

