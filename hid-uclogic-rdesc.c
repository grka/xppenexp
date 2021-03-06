// SPDX-License-Identifier: GPL-2.0+
/*
 *  HID driver for UC-Logic devices not fully compliant with HID standard
 *  - original and fixed report descriptors
 *
 *  Copyright (c) 2010-2017 Nikolai Kondrashov
 *  Copyright (c) 2013 Martin Rusko
 */

/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include "hid-uclogic-rdesc.h"
#include <linux/slab.h>
#include <asm/unaligned.h>

/* Fixed WP4030U report descriptor */
__u8 uclogic_rdesc_wp4030u_fixed_arr[] = {
	0x05, 0x0D,         /*  Usage Page (Digitizer),             */
	0x09, 0x02,         /*  Usage (Pen),                        */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x09,         /*      Report ID (9),                  */
	0x09, 0x20,         /*      Usage (Stylus),                 */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x09, 0x42,         /*          Usage (Tip Switch),         */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x09, 0x46,         /*          Usage (Tablet Pick),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x75, 0x10,         /*          Report Size (16),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x14,               /*          Logical Minimum (0),        */
	0xA4,               /*          Push,                       */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x55, 0xFD,         /*          Unit Exponent (-3),         */
	0x65, 0x13,         /*          Unit (Inch),                */
	0x34,               /*          Physical Minimum (0),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x46, 0xA0, 0x0F,   /*          Physical Maximum (4000),    */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x46, 0xB8, 0x0B,   /*          Physical Maximum (3000),    */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0xB4,               /*          Pop,                        */
	0x09, 0x30,         /*          Usage (Tip Pressure),       */
	0x26, 0xFF, 0x03,   /*          Logical Maximum (1023),     */
	0x81, 0x02,         /*          Input (Variable),           */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_wp4030u_fixed_size =
			sizeof(uclogic_rdesc_wp4030u_fixed_arr);

/* Fixed WP5540U report descriptor */
__u8 uclogic_rdesc_wp5540u_fixed_arr[] = {
	0x05, 0x0D,         /*  Usage Page (Digitizer),             */
	0x09, 0x02,         /*  Usage (Pen),                        */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x09,         /*      Report ID (9),                  */
	0x09, 0x20,         /*      Usage (Stylus),                 */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x09, 0x42,         /*          Usage (Tip Switch),         */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x09, 0x46,         /*          Usage (Tablet Pick),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x75, 0x10,         /*          Report Size (16),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x14,               /*          Logical Minimum (0),        */
	0xA4,               /*          Push,                       */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x55, 0xFD,         /*          Unit Exponent (-3),         */
	0x65, 0x13,         /*          Unit (Inch),                */
	0x34,               /*          Physical Minimum (0),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x46, 0x7C, 0x15,   /*          Physical Maximum (5500),    */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x46, 0xA0, 0x0F,   /*          Physical Maximum (4000),    */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0xB4,               /*          Pop,                        */
	0x09, 0x30,         /*          Usage (Tip Pressure),       */
	0x26, 0xFF, 0x03,   /*          Logical Maximum (1023),     */
	0x81, 0x02,         /*          Input (Variable),           */
	0xC0,               /*      End Collection,                 */
	0xC0,               /*  End Collection,                     */
	0x05, 0x01,         /*  Usage Page (Desktop),               */
	0x09, 0x02,         /*  Usage (Mouse),                      */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x08,         /*      Report ID (8),                  */
	0x09, 0x01,         /*      Usage (Pointer),                */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x05, 0x09,         /*          Usage Page (Button),        */
	0x19, 0x01,         /*          Usage Minimum (01h),        */
	0x29, 0x03,         /*          Usage Maximum (03h),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x75, 0x08,         /*          Report Size (8),            */
	0x09, 0x30,         /*          Usage (X),                  */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x15, 0x81,         /*          Logical Minimum (-127),     */
	0x25, 0x7F,         /*          Logical Maximum (127),      */
	0x95, 0x02,         /*          Report Count (2),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x09, 0x38,         /*          Usage (Wheel),              */
	0x15, 0xFF,         /*          Logical Minimum (-1),       */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x81, 0x01,         /*          Input (Constant),           */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_wp5540u_fixed_size =
			sizeof(uclogic_rdesc_wp5540u_fixed_arr);

/* Fixed WP8060U report descriptor */
__u8 uclogic_rdesc_wp8060u_fixed_arr[] = {
	0x05, 0x0D,         /*  Usage Page (Digitizer),             */
	0x09, 0x02,         /*  Usage (Pen),                        */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x09,         /*      Report ID (9),                  */
	0x09, 0x20,         /*      Usage (Stylus),                 */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x09, 0x42,         /*          Usage (Tip Switch),         */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x09, 0x46,         /*          Usage (Tablet Pick),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x75, 0x10,         /*          Report Size (16),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x14,               /*          Logical Minimum (0),        */
	0xA4,               /*          Push,                       */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x55, 0xFD,         /*          Unit Exponent (-3),         */
	0x65, 0x13,         /*          Unit (Inch),                */
	0x34,               /*          Physical Minimum (0),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x46, 0x40, 0x1F,   /*          Physical Maximum (8000),    */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x46, 0x70, 0x17,   /*          Physical Maximum (6000),    */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0xB4,               /*          Pop,                        */
	0x09, 0x30,         /*          Usage (Tip Pressure),       */
	0x26, 0xFF, 0x03,   /*          Logical Maximum (1023),     */
	0x81, 0x02,         /*          Input (Variable),           */
	0xC0,               /*      End Collection,                 */
	0xC0,               /*  End Collection,                     */
	0x05, 0x01,         /*  Usage Page (Desktop),               */
	0x09, 0x02,         /*  Usage (Mouse),                      */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x08,         /*      Report ID (8),                  */
	0x09, 0x01,         /*      Usage (Pointer),                */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x05, 0x09,         /*          Usage Page (Button),        */
	0x19, 0x01,         /*          Usage Minimum (01h),        */
	0x29, 0x03,         /*          Usage Maximum (03h),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x75, 0x08,         /*          Report Size (8),            */
	0x09, 0x30,         /*          Usage (X),                  */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x15, 0x81,         /*          Logical Minimum (-127),     */
	0x25, 0x7F,         /*          Logical Maximum (127),      */
	0x95, 0x02,         /*          Report Count (2),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x09, 0x38,         /*          Usage (Wheel),              */
	0x15, 0xFF,         /*          Logical Minimum (-1),       */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x81, 0x01,         /*          Input (Constant),           */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_wp8060u_fixed_size =
			sizeof(uclogic_rdesc_wp8060u_fixed_arr);

/* Fixed WP1062 report descriptor */
__u8 uclogic_rdesc_wp1062_fixed_arr[] = {
	0x05, 0x0D,         /*  Usage Page (Digitizer),             */
	0x09, 0x02,         /*  Usage (Pen),                        */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x09,         /*      Report ID (9),                  */
	0x09, 0x20,         /*      Usage (Stylus),                 */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x09, 0x42,         /*          Usage (Tip Switch),         */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x09, 0x46,         /*          Usage (Tablet Pick),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x04,         /*          Report Count (4),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x09, 0x32,         /*          Usage (In Range),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x75, 0x10,         /*          Report Size (16),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x14,               /*          Logical Minimum (0),        */
	0xA4,               /*          Push,                       */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x55, 0xFD,         /*          Unit Exponent (-3),         */
	0x65, 0x13,         /*          Unit (Inch),                */
	0x34,               /*          Physical Minimum (0),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x46, 0x10, 0x27,   /*          Physical Maximum (10000),   */
	0x26, 0x20, 0x4E,   /*          Logical Maximum (20000),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x46, 0xB7, 0x19,   /*          Physical Maximum (6583),    */
	0x26, 0x6E, 0x33,   /*          Logical Maximum (13166),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0xB4,               /*          Pop,                        */
	0x09, 0x30,         /*          Usage (Tip Pressure),       */
	0x26, 0xFF, 0x03,   /*          Logical Maximum (1023),     */
	0x81, 0x02,         /*          Input (Variable),           */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_wp1062_fixed_size =
			sizeof(uclogic_rdesc_wp1062_fixed_arr);

/* Fixed PF1209 report descriptor */
__u8 uclogic_rdesc_pf1209_fixed_arr[] = {
	0x05, 0x0D,         /*  Usage Page (Digitizer),             */
	0x09, 0x02,         /*  Usage (Pen),                        */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x09,         /*      Report ID (9),                  */
	0x09, 0x20,         /*      Usage (Stylus),                 */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x09, 0x42,         /*          Usage (Tip Switch),         */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x09, 0x46,         /*          Usage (Tablet Pick),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x75, 0x10,         /*          Report Size (16),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x14,               /*          Logical Minimum (0),        */
	0xA4,               /*          Push,                       */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x55, 0xFD,         /*          Unit Exponent (-3),         */
	0x65, 0x13,         /*          Unit (Inch),                */
	0x34,               /*          Physical Minimum (0),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x46, 0xE0, 0x2E,   /*          Physical Maximum (12000),   */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x46, 0x28, 0x23,   /*          Physical Maximum (9000),    */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0xB4,               /*          Pop,                        */
	0x09, 0x30,         /*          Usage (Tip Pressure),       */
	0x26, 0xFF, 0x03,   /*          Logical Maximum (1023),     */
	0x81, 0x02,         /*          Input (Variable),           */
	0xC0,               /*      End Collection,                 */
	0xC0,               /*  End Collection,                     */
	0x05, 0x01,         /*  Usage Page (Desktop),               */
	0x09, 0x02,         /*  Usage (Mouse),                      */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x08,         /*      Report ID (8),                  */
	0x09, 0x01,         /*      Usage (Pointer),                */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x05, 0x09,         /*          Usage Page (Button),        */
	0x19, 0x01,         /*          Usage Minimum (01h),        */
	0x29, 0x03,         /*          Usage Maximum (03h),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x75, 0x08,         /*          Report Size (8),            */
	0x09, 0x30,         /*          Usage (X),                  */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x15, 0x81,         /*          Logical Minimum (-127),     */
	0x25, 0x7F,         /*          Logical Maximum (127),      */
	0x95, 0x02,         /*          Report Count (2),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x09, 0x38,         /*          Usage (Wheel),              */
	0x15, 0xFF,         /*          Logical Minimum (-1),       */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x81, 0x01,         /*          Input (Constant),           */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_pf1209_fixed_size =
			sizeof(uclogic_rdesc_pf1209_fixed_arr);

/* Fixed PID 0522 tablet report descriptor, interface 0 (stylus) */
__u8 uclogic_rdesc_twhl850_fixed0_arr[] = {
	0x05, 0x0D,         /*  Usage Page (Digitizer),             */
	0x09, 0x02,         /*  Usage (Pen),                        */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x09,         /*      Report ID (9),                  */
	0x09, 0x20,         /*      Usage (Stylus),                 */
	0xA0,               /*      Collection (Physical),          */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x75, 0x01,         /*          Report Size (1),            */
	0x95, 0x03,         /*          Report Count (3),           */
	0x09, 0x42,         /*          Usage (Tip Switch),         */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x09, 0x46,         /*          Usage (Tablet Pick),        */
	0x81, 0x02,         /*          Input (Variable),           */
	0x81, 0x03,         /*          Input (Constant, Variable), */
	0x95, 0x01,         /*          Report Count (1),           */
	0x09, 0x32,         /*          Usage (In Range),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x81, 0x03,         /*          Input (Constant, Variable), */
	0x75, 0x10,         /*          Report Size (16),           */
	0xA4,               /*          Push,                       */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x65, 0x13,         /*          Unit (Inch),                */
	0x55, 0xFD,         /*          Unit Exponent (-3),         */
	0x34,               /*          Physical Minimum (0),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x46, 0x40, 0x1F,   /*          Physical Maximum (8000),    */
	0x26, 0x00, 0x7D,   /*          Logical Maximum (32000),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x46, 0x88, 0x13,   /*          Physical Maximum (5000),    */
	0x26, 0x20, 0x4E,   /*          Logical Maximum (20000),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0xB4,               /*          Pop,                        */
	0x09, 0x30,         /*          Usage (Tip Pressure),       */
	0x26, 0xFF, 0x03,   /*          Logical Maximum (1023),     */
	0x81, 0x02,         /*          Input (Variable),           */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_twhl850_fixed0_size =
			sizeof(uclogic_rdesc_twhl850_fixed0_arr);

/* Fixed PID 0522 tablet report descriptor, interface 1 (mouse) */
__u8 uclogic_rdesc_twhl850_fixed1_arr[] = {
	0x05, 0x01,         /*  Usage Page (Desktop),               */
	0x09, 0x02,         /*  Usage (Mouse),                      */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x01,         /*      Report ID (1),                  */
	0x09, 0x01,         /*      Usage (Pointer),                */
	0xA0,               /*      Collection (Physical),          */
	0x05, 0x09,         /*          Usage Page (Button),        */
	0x75, 0x01,         /*          Report Size (1),            */
	0x95, 0x03,         /*          Report Count (3),           */
	0x19, 0x01,         /*          Usage Minimum (01h),        */
	0x29, 0x03,         /*          Usage Maximum (03h),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x03,         /*          Input (Constant, Variable), */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x16, 0x00, 0x80,   /*          Logical Minimum (-32768),   */
	0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
	0x75, 0x10,         /*          Report Size (16),           */
	0x95, 0x02,         /*          Report Count (2),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x09, 0x38,         /*          Usage (Wheel),              */
	0x15, 0xFF,         /*          Logical Minimum (-1),       */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x01,         /*          Report Count (1),           */
	0x75, 0x08,         /*          Report Size (8),            */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0x81, 0x03,         /*          Input (Constant, Variable), */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_twhl850_fixed1_size =
			sizeof(uclogic_rdesc_twhl850_fixed1_arr);

/* Fixed PID 0522 tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_twhl850_fixed2_arr[] = {
	0x05, 0x01,         /*  Usage Page (Desktop),               */
	0x09, 0x06,         /*  Usage (Keyboard),                   */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x03,         /*      Report ID (3),                  */
	0x05, 0x07,         /*      Usage Page (Keyboard),          */
	0x14,               /*      Logical Minimum (0),            */
	0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol), */
	0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),   */
	0x25, 0x01,         /*      Logical Maximum (1),            */
	0x75, 0x01,         /*      Report Size (1),                */
	0x95, 0x08,         /*      Report Count (8),               */
	0x81, 0x02,         /*      Input (Variable),               */
	0x18,               /*      Usage Minimum (None),           */
	0x29, 0xFF,         /*      Usage Maximum (FFh),            */
	0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
	0x75, 0x08,         /*      Report Size (8),                */
	0x95, 0x06,         /*      Report Count (6),               */
	0x80,               /*      Input,                          */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_twhl850_fixed2_size =
			sizeof(uclogic_rdesc_twhl850_fixed2_arr);

/* Fixed TWHA60 report descriptor, interface 0 (stylus) */
__u8 uclogic_rdesc_twha60_fixed0_arr[] = {
	0x05, 0x0D,         /*  Usage Page (Digitizer),             */
	0x09, 0x02,         /*  Usage (Pen),                        */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x09,         /*      Report ID (9),                  */
	0x09, 0x20,         /*      Usage (Stylus),                 */
	0xA0,               /*      Collection (Physical),          */
	0x75, 0x01,         /*          Report Size (1),            */
	0x09, 0x42,         /*          Usage (Tip Switch),         */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x09, 0x46,         /*          Usage (Tablet Pick),        */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x95, 0x04,         /*          Report Count (4),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x09, 0x32,         /*          Usage (In Range),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x75, 0x10,         /*          Report Size (16),           */
	0x95, 0x01,         /*          Report Count (1),           */
	0x14,               /*          Logical Minimum (0),        */
	0xA4,               /*          Push,                       */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x55, 0xFD,         /*          Unit Exponent (-3),         */
	0x65, 0x13,         /*          Unit (Inch),                */
	0x34,               /*          Physical Minimum (0),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x46, 0x10, 0x27,   /*          Physical Maximum (10000),   */
	0x27, 0x3F, 0x9C,
		0x00, 0x00, /*          Logical Maximum (39999),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x46, 0x6A, 0x18,   /*          Physical Maximum (6250),    */
	0x26, 0xA7, 0x61,   /*          Logical Maximum (24999),    */
	0x81, 0x02,         /*          Input (Variable),           */
	0xB4,               /*          Pop,                        */
	0x09, 0x30,         /*          Usage (Tip Pressure),       */
	0x26, 0xFF, 0x03,   /*          Logical Maximum (1023),     */
	0x81, 0x02,         /*          Input (Variable),           */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_twha60_fixed0_size =
			sizeof(uclogic_rdesc_twha60_fixed0_arr);

/* Fixed TWHA60 report descriptor, interface 1 (frame buttons) */
__u8 uclogic_rdesc_twha60_fixed1_arr[] = {
	0x05, 0x01, /*  Usage Page (Desktop),       */
	0x09, 0x06, /*  Usage (Keyboard),           */
	0xA1, 0x01, /*  Collection (Application),   */
	0x85, 0x05, /*      Report ID (5),          */
	0x05, 0x07, /*      Usage Page (Keyboard),  */
	0x14,       /*      Logical Minimum (0),    */
	0x25, 0x01, /*      Logical Maximum (1),    */
	0x75, 0x01, /*      Report Size (1),        */
	0x95, 0x08, /*      Report Count (8),       */
	0x81, 0x01, /*      Input (Constant),       */
	0x95, 0x0C, /*      Report Count (12),      */
	0x19, 0x3A, /*      Usage Minimum (KB F1),  */
	0x29, 0x45, /*      Usage Maximum (KB F12), */
	0x81, 0x02, /*      Input (Variable),       */
	0x95, 0x0C, /*      Report Count (12),      */
	0x19, 0x68, /*      Usage Minimum (KB F13), */
	0x29, 0x73, /*      Usage Maximum (KB F24), */
	0x81, 0x02, /*      Input (Variable),       */
	0x95, 0x08, /*      Report Count (8),       */
	0x81, 0x01, /*      Input (Constant),       */
	0xC0        /*  End Collection              */
};

const size_t uclogic_rdesc_twha60_fixed1_size =
			sizeof(uclogic_rdesc_twha60_fixed1_arr);

/* Fixed report descriptor template for (tweaked) v1 pen reports */
const __u8 uclogic_rdesc_pen_v1_template_arr[] = {
	0x05, 0x0D,             /*  Usage Page (Digitizer),                 */
	0x09, 0x02,             /*  Usage (Pen),                            */
	0xA1, 0x01,             /*  Collection (Application),               */
	0x85, 0x07,             /*      Report ID (7),                      */
	0x09, 0x20,             /*      Usage (Stylus),                     */
	0xA0,                   /*      Collection (Physical),              */
	0x14,                   /*          Logical Minimum (0),            */
	0x25, 0x01,             /*          Logical Maximum (1),            */
	0x75, 0x01,             /*          Report Size (1),                */
	0x09, 0x42,             /*          Usage (Tip Switch),             */
	0x09, 0x44,             /*          Usage (Barrel Switch),          */
	0x09, 0x46,             /*          Usage (Tablet Pick),            */
	0x95, 0x03,             /*          Report Count (3),               */
	0x81, 0x02,             /*          Input (Variable),               */
	0x95, 0x03,             /*          Report Count (3),               */
	0x81, 0x03,             /*          Input (Constant, Variable),     */
	0x09, 0x32,             /*          Usage (In Range),               */
	0x95, 0x01,             /*          Report Count (1),               */
	0x81, 0x02,             /*          Input (Variable),               */
	0x95, 0x01,             /*          Report Count (1),               */
	0x81, 0x03,             /*          Input (Constant, Variable),     */
	0x75, 0x10,             /*          Report Size (16),               */
	0x95, 0x01,             /*          Report Count (1),               */
	0xA4,                   /*          Push,                           */
	0x05, 0x01,             /*          Usage Page (Desktop),           */
	0x65, 0x13,             /*          Unit (Inch),                    */
	0x55, 0xFD,             /*          Unit Exponent (-3),             */
	0x34,                   /*          Physical Minimum (0),           */
	0x09, 0x30,             /*          Usage (X),                      */
	0x27, UCLOGIC_RDESC_PEN_PH(X_LM),
				/*          Logical Maximum (PLACEHOLDER),  */
	0x47, UCLOGIC_RDESC_PEN_PH(X_PM),
				/*          Physical Maximum (PLACEHOLDER), */
	0x81, 0x02,             /*          Input (Variable),               */
	0x09, 0x31,             /*          Usage (Y),                      */
	0x27, UCLOGIC_RDESC_PEN_PH(Y_LM),
				/*          Logical Maximum (PLACEHOLDER),  */
	0x47, UCLOGIC_RDESC_PEN_PH(Y_PM),
				/*          Physical Maximum (PLACEHOLDER), */
	0x81, 0x02,             /*          Input (Variable),               */
	0xB4,                   /*          Pop,                            */
	0x09, 0x30,             /*          Usage (Tip Pressure),           */
	0x27, UCLOGIC_RDESC_PEN_PH(PRESSURE_LM),
				/*          Logical Maximum (PLACEHOLDER),  */
	0x81, 0x02,             /*          Input (Variable),               */
	0xC0,                   /*      End Collection,                     */
	0xC0                    /*  End Collection                          */
};

const size_t uclogic_rdesc_pen_v1_template_size =
			sizeof(uclogic_rdesc_pen_v1_template_arr);

/* Fixed report descriptor template for (tweaked) v2 pen reports */
const __u8 uclogic_rdesc_pen_v2_template_arr[] = {
	0x05, 0x0D,             /*  Usage Page (Digitizer),                 */
	0x09, 0x02,             /*  Usage (Pen),                            */
	0xA1, 0x01,             /*  Collection (Application),               */
	0x85, 0x08,             /*      Report ID (8),                      */
	0x09, 0x20,             /*      Usage (Stylus),                     */
	0xA0,                   /*      Collection (Physical),              */
	0x14,                   /*          Logical Minimum (0),            */
	0x25, 0x01,             /*          Logical Maximum (1),            */
	0x75, 0x01,             /*          Report Size (1),                */
	0x09, 0x42,             /*          Usage (Tip Switch),             */
	0x09, 0x44,             /*          Usage (Barrel Switch),          */
	0x09, 0x46,             /*          Usage (Tablet Pick),            */
	0x95, 0x03,             /*          Report Count (3),               */
	0x81, 0x02,             /*          Input (Variable),               */
	0x95, 0x03,             /*          Report Count (3),               */
	0x81, 0x03,             /*          Input (Constant, Variable),     */
	0x09, 0x32,             /*          Usage (In Range),               */
	0x95, 0x01,             /*          Report Count (1),               */
	0x81, 0x02,             /*          Input (Variable),               */
	0x95, 0x01,             /*          Report Count (1),               */
	0x81, 0x03,             /*          Input (Constant, Variable),     */
	0x95, 0x01,             /*          Report Count (1),               */
	0xA4,                   /*          Push,                           */
	0x05, 0x01,             /*          Usage Page (Desktop),           */
	0x65, 0x13,             /*          Unit (Inch),                    */
	0x55, 0xFD,             /*          Unit Exponent (-3),             */
	0x75, 0x18,             /*          Report Size (24),               */
	0x34,                   /*          Physical Minimum (0),           */
	0x09, 0x30,             /*          Usage (X),                      */
	0x27, UCLOGIC_RDESC_PEN_PH(X_LM),
				/*          Logical Maximum (PLACEHOLDER),  */
	0x47, UCLOGIC_RDESC_PEN_PH(X_PM),
				/*          Physical Maximum (PLACEHOLDER), */
	0x81, 0x02,             /*          Input (Variable),               */
	0x09, 0x31,             /*          Usage (Y),                      */
	0x27, UCLOGIC_RDESC_PEN_PH(Y_LM),
				/*          Logical Maximum (PLACEHOLDER),  */
	0x47, UCLOGIC_RDESC_PEN_PH(Y_PM),
				/*          Physical Maximum (PLACEHOLDER), */
	0x81, 0x02,             /*          Input (Variable),               */
	0xB4,                   /*          Pop,                            */
	0x09, 0x30,             /*          Usage (Tip Pressure),           */
	0x75, 0x10,             /*          Report Size (16),               */
	0x27, UCLOGIC_RDESC_PEN_PH(PRESSURE_LM),
				/*          Logical Maximum (PLACEHOLDER),  */
	0x81, 0x02,             /*          Input (Variable),               */
	0x54,                   /*          Unit Exponent (0),              */
	0x65, 0x14,             /*          Unit (Degrees),                 */
	0x35, 0xC4,             /*          Physical Minimum (-60),         */
	0x45, 0x3C,             /*          Physical Maximum (60),          */
	0x15, 0xC4,             /*          Logical Minimum (-60),          */
	0x25, 0x3C,             /*          Logical Maximum (60),           */
	0x75, 0x08,             /*          Report Size (8),                */
	0x95, 0x02,             /*          Report Count (2),               */
	0x09, 0x3D,             /*          Usage (X Tilt),                 */
	0x09, 0x3E,             /*          Usage (Y Tilt),                 */
	0x81, 0x02,             /*          Input (Variable),               */
	0xC0,                   /*      End Collection,                     */
	0xC0                    /*  End Collection                          */
};

const size_t uclogic_rdesc_pen_v2_template_size =
			sizeof(uclogic_rdesc_pen_v2_template_arr);

/**
 * Expand to the contents of a generic buttonpad report descriptor.
 *
 * @_padding:	Padding from the end of button bits at bit 44, until
 *		the end of the report, in bits.
 */
#define UCLOGIC_RDESC_BUTTONPAD_BYTES(_padding) \
	0x05, 0x01,     /*  Usage Page (Desktop),               */ \
	0x09, 0x07,     /*  Usage (Keypad),                     */ \
	0xA1, 0x01,     /*  Collection (Application),           */ \
	0x85, 0xF7,     /*      Report ID (247),                */ \
	0x14,           /*      Logical Minimum (0),            */ \
	0x25, 0x01,     /*      Logical Maximum (1),            */ \
	0x75, 0x01,     /*      Report Size (1),                */ \
	0x05, 0x0D,     /*      Usage Page (Digitizer),         */ \
	0x09, 0x39,     /*      Usage (Tablet Function Keys),   */ \
	0xA0,           /*      Collection (Physical),          */ \
	0x09, 0x44,     /*          Usage (Barrel Switch),      */ \
	0x95, 0x01,     /*          Report Count (1),           */ \
	0x81, 0x02,     /*          Input (Variable),           */ \
	0x05, 0x01,     /*          Usage Page (Desktop),       */ \
	0x09, 0x30,     /*          Usage (X),                  */ \
	0x09, 0x31,     /*          Usage (Y),                  */ \
	0x95, 0x02,     /*          Report Count (2),           */ \
	0x81, 0x02,     /*          Input (Variable),           */ \
	0x95, 0x15,     /*          Report Count (21),          */ \
	0x81, 0x01,     /*          Input (Constant),           */ \
	0x05, 0x09,     /*          Usage Page (Button),        */ \
	0x19, 0x01,     /*          Usage Minimum (01h),        */ \
	0x29, 0x0A,     /*          Usage Maximum (0Ah),        */ \
	0x95, 0x0A,     /*          Report Count (10),          */ \
	0x81, 0x02,     /*          Input (Variable),           */ \
	0xC0,           /*      End Collection,                 */ \
	0x05, 0x01,     /*      Usage Page (Desktop),           */ \
	0x09, 0x05,     /*      Usage (Gamepad),                */ \
	0xA0,           /*      Collection (Physical),          */ \
	0x05, 0x09,     /*          Usage Page (Button),        */ \
	0x19, 0x01,     /*          Usage Minimum (01h),        */ \
	0x29, 0x02,     /*          Usage Maximum (02h),        */ \
	0x95, 0x02,     /*          Report Count (2),           */ \
	0x81, 0x02,     /*          Input (Variable),           */ \
	0x95, _padding, /*          Report Count (_padding),    */ \
	0x81, 0x01,     /*          Input (Constant),           */ \
	0xC0,           /*      End Collection,                 */ \
	0xC0            /*  End Collection                      */

/* Fixed report descriptor for (tweaked) v1 buttonpad reports */
const __u8 uclogic_rdesc_buttonpad_v1_arr[] = {
	UCLOGIC_RDESC_BUTTONPAD_BYTES(20)
};
const size_t uclogic_rdesc_buttonpad_v1_size =
			sizeof(uclogic_rdesc_buttonpad_v1_arr);

/* Fixed report descriptor for (tweaked) v2 buttonpad reports */
const __u8 uclogic_rdesc_buttonpad_v2_arr[] = {
	UCLOGIC_RDESC_BUTTONPAD_BYTES(52)
};
const size_t uclogic_rdesc_buttonpad_v2_size =
			sizeof(uclogic_rdesc_buttonpad_v2_arr);

/* Fixed report descriptor for Ugee EX07 buttonpad */
const __u8 uclogic_rdesc_ugee_ex07_buttonpad_arr[] = {
	0x05, 0x01,             /*  Usage Page (Desktop),                   */
	0x09, 0x07,             /*  Usage (Keypad),                         */
	0xA1, 0x01,             /*  Collection (Application),               */
	0x85, 0x06,             /*      Report ID (6),                      */
	0x05, 0x0D,             /*      Usage Page (Digitizer),             */
	0x09, 0x39,             /*      Usage (Tablet Function Keys),       */
	0xA0,                   /*      Collection (Physical),              */
	0x05, 0x09,             /*          Usage Page (Button),            */
	0x75, 0x01,             /*          Report Size (1),                */
	0x19, 0x03,             /*          Usage Minimum (03h),            */
	0x29, 0x06,             /*          Usage Maximum (06h),            */
	0x95, 0x04,             /*          Report Count (4),               */
	0x81, 0x02,             /*          Input (Variable),               */
	0x95, 0x1A,             /*          Report Count (26),              */
	0x81, 0x03,             /*          Input (Constant, Variable),     */
	0x19, 0x01,             /*          Usage Minimum (01h),            */
	0x29, 0x02,             /*          Usage Maximum (02h),            */
	0x95, 0x02,             /*          Report Count (2),               */
	0x81, 0x02,             /*          Input (Variable),               */
	0xC0,                   /*      End Collection,                     */
	0xC0                    /*  End Collection                          */
};
const size_t uclogic_rdesc_ugee_ex07_buttonpad_size =
			sizeof(uclogic_rdesc_ugee_ex07_buttonpad_arr);

/* Fixed report descriptor for Ugee G5 frame controls */
const __u8 uclogic_rdesc_ugee_g5_frame_arr[] = {
	0x05, 0x01,         /*  Usage Page (Desktop),               */
	0x09, 0x07,         /*  Usage (Keypad),                     */
	0xA1, 0x01,         /*  Collection (Application),           */
	0x85, 0x06,         /*      Report ID (6),                  */
	0x05, 0x0D,         /*      Usage Page (Digitizer),         */
	0x09, 0x39,         /*      Usage (Tablet Function Keys),   */
	0xA0,               /*      Collection (Physical),          */
	0x14,               /*          Logical Minimum (0),        */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x05, 0x09,         /*          Usage Page (Button),        */
	0x19, 0x01,         /*          Usage Minimum (01h),        */
	0x29, 0x05,         /*          Usage Maximum (05h),        */
	0x75, 0x01,         /*          Report Size (1),            */
	0x95, 0x05,         /*          Report Count (5),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x75, 0x01,         /*          Report Size (1),            */
	0x95, 0x03,         /*          Report Count (3),           */
	0x81, 0x01,         /*          Input (Constant),           */
	0x05, 0x0D,         /*          Usage Page (Digitizer),     */
	0x0A, 0xFF, 0xFF,   /*          Usage (FFFFh),              */
	0x26, 0xFF, 0x00,   /*          Logical Maximum (255),      */
	0x75, 0x08,         /*          Report Size (8),            */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x09, 0x44,         /*          Usage (Barrel Switch),      */
	0x75, 0x01,         /*          Report Size (1),            */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x09, 0x30,         /*          Usage (X),                  */
	0x09, 0x31,         /*          Usage (Y),                  */
	0x75, 0x01,         /*          Report Size (1),            */
	0x95, 0x02,         /*          Report Count (2),           */
	0x81, 0x02,         /*          Input (Variable),           */
	0x75, 0x01,         /*          Report Size (1),            */
	0x95, 0x0B,         /*          Report Count (11),          */
	0x81, 0x01,         /*          Input (Constant),           */
	0x05, 0x01,         /*          Usage Page (Desktop),       */
	0x09, 0x38,         /*          Usage (Wheel),              */
	0x15, 0xFF,         /*          Logical Minimum (-1),       */
	0x25, 0x01,         /*          Logical Maximum (1),        */
	0x75, 0x02,         /*          Report Size (2),            */
	0x95, 0x01,         /*          Report Count (1),           */
	0x81, 0x06,         /*          Input (Variable, Relative), */
	0xC0,               /*      End Collection,                 */
	0xC0                /*  End Collection                      */
};
const size_t uclogic_rdesc_ugee_g5_frame_size =
			sizeof(uclogic_rdesc_ugee_g5_frame_arr);
			

/* Fixed STAR01 tablet report descriptor, interface 0 (stylus) */
__u8 uclogic_rdesc_star01_fixed0_arr[] = {
0x05, 0x0D,         /*  Usage Page (Digitizer),                         */
0x09, 0x02,         /*  Usage (Pen),                                    */
0xA1, 0x01,         /*  Collection (Application),                       */
0x85, 0x07,         /*      Report ID (7),                              */
0x09, 0x20,         /*      Usage (Stylus),                             */
0xA1, 0x00,         /*      Collection (Physical),                      */
0x09, 0x42,         /*          Usage (Tip Switch),                     */
0x09, 0x44,         /*          Usage (Barrel Switch),                  */
0x09, 0x45,         /*          Usage (Eraser),                         */
0x09, 0x3C,         /*          Usage (Invert),                         */
0x09, 0x43,         /*          Usage (Secondary Tip Switch),           */
0x09, 0x44,         /*          Usage (Barrel Switch),                  */
0x15, 0x00,         /*          Logical Minimum (0),                    */
0x25, 0x01,         /*          Logical Maximum (1),                    */
0x75, 0x01,         /*          Report Size (1),                        */
0x95, 0x06,         /*          Report Count (6),                       */
0x81, 0x02,         /*          Input (Variable),                       */
0x09, 0x32,         /*          Usage (In Range),                       */
0x75, 0x01,         /*          Report Size (1),                        */
0x95, 0x01,         /*          Report Count (1),                       */
0x81, 0x02,         /*          Input (Variable),                       */
0x81, 0x03,         /*          Input (Constant, Variable),             */
0x05, 0x01,         /*          Usage Page (Desktop),                   */
0x09, 0x30,         /*          Usage (X),                              */
0x75, 0x10,         /*          Report Size (16),                       */
0x95, 0x01,         /*          Report Count (1),                       */
0xA4,               /*          Push,                                   */
0x55, 0x0D,         /*          Unit Exponent (13),                     */
0x65, 0x13,         /*          Unit (Inch),                            */
0x35, 0x00,         /*          Physical Minimum (0),                   */
0x46, 0x40, 0x1F,   /*          Physical Maximum (8000),                */
0x26, 0x00, 0x7D,   /*          Logical Maximum (32000),                */
0x81, 0x02,         /*          Input (Variable),                       */
0x09, 0x31,         /*          Usage (Y),                              */
0x46, 0x88, 0x13,   /*          Physical Maximum (5000),                */
0x26, 0x20, 0x4E,   /*          Logical Maximum (20000),                */
0x81, 0x02,         /*          Input (Variable),                       */
0xB4,               /*          Pop,                                    */
0x05, 0x0D,         /*          Usage Page (Digitizer),                 */
0x09, 0x30,         /*          Usage (Tip Pressure),                   */
0x26, 0xFF, 0x07,   /*          Logical Maximum (2047),                 */
0x46, 0xFF, 0x07,   /*          Physical Maximum (2047),                */
0x55, 0x00,         /*          Unit Exponent (0),                      */
0x66, 0x11, 0xE1,   /*          Unit (Centimeter * Gram * Seconds^-2),  */
0x75, 0x10,         /*          Report Size (16),                       */
0x81, 0x02,         /*          Input (Variable),                       */
0xC0,               /*      End Collection,                             */
0xC0,               /*  End Collection,                                 */
0x05, 0x01,         /*  Usage Page (Desktop),                           */
0x09, 0x02,         /*  Usage (Mouse),                                  */
0xA1, 0x01,         /*  Collection (Application),                       */
0x85, 0x09,         /*      Report ID (9),                              */
0x09, 0x01,         /*      Usage (Pointer),                            */
0xA1, 0x00,         /*      Collection (Physical),                      */
0x05, 0x09,         /*          Usage Page (Button),                    */
0x19, 0x01,         /*          Usage Minimum (01h),                    */
0x29, 0x03,         /*          Usage Maximum (03h),                    */
0x15, 0x00,         /*          Logical Minimum (0),                    */
0x25, 0x01,         /*          Logical Maximum (1),                    */
0x95, 0x03,         /*          Report Count (3),                       */
0x75, 0x01,         /*          Report Size (1),                        */
0x81, 0x02,         /*          Input (Variable),                       */
0x95, 0x05,         /*          Report Count (5),                       */
0x81, 0x01,         /*          Input (Constant),                       */
0x05, 0x01,         /*          Usage Page (Desktop),                   */
0x09, 0x30,         /*          Usage (X),                              */
0x75, 0x10,         /*          Report Size (16),                       */
0x95, 0x01,         /*          Report Count (1),                       */
0xA4,               /*          Push,                                   */
0x35, 0x00,         /*          Physical Minimum (0),                   */
0x46, 0x40, 0x1F,   /*          Physical Maximum (8000),                */
0x26, 0x40, 0x1F,   /*          Logical Maximum (8000),                 */
0x81, 0x02,         /*          Input (Variable),                       */
0x09, 0x31,         /*          Usage (Y),                              */
0x46, 0x40, 0x1F,   /*          Physical Maximum (8000),                */
0x26, 0x40, 0x1F,   /*          Logical Maximum (8000),                 */
0x81, 0x02,         /*          Input (Variable),                       */
0xB4,               /*          Pop,                                    */
0x05, 0x0D,         /*          Usage Page (Digitizer),                 */
0x09, 0x30,         /*          Usage (Tip Pressure),                   */
0x26, 0xFF, 0x07,   /*          Logical Maximum (2047),                 */
0x46, 0xFF, 0x07,   /*          Physical Maximum (2047),                */
0x75, 0x10,         /*          Report Size (16),                       */
0x81, 0x02,         /*          Input (Variable),                       */
0xC0,               /*      End Collection,                             */
0xC0                /*  End Collection                                  */
};

const size_t uclogic_rdesc_star01_fixed0_size =
			sizeof(uclogic_rdesc_star01_fixed0_arr);

/* Fixed STAR01 tablet report descriptor, interface 1 (mouse) */
__u8 uclogic_rdesc_star01_fixed1_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x85, 0x01,         /*          Report ID (1),              */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x05,         /*          Usage Maximum (05h),        */
0x95, 0x05,         /*          Report Count (5),           */
0x75, 0x01,         /*          Report Size (1),            */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x03,         /*          Report Count (3),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x16, 0x00, 0x80,   /*          Logical Minimum (-32768),   */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x81, 0x06,         /*          Input (Variable, Relative), */
0x09, 0x38,         /*          Usage (Wheel),              */
0x15, 0x81,         /*          Logical Minimum (-127),     */
0x25, 0x7F,         /*          Logical Maximum (127),      */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x08,         /*          Report Size (8),            */
0x81, 0x06,         /*          Input (Variable, Relative), */
0x05, 0x0C,         /*          Usage Page (Consumer),      */
0x0A, 0x38, 0x02,   /*          Usage (AC Pan),             */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x08,         /*          Report Size (8),            */
0x81, 0x06,         /*          Input (Variable, Relative), */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x06, 0x01, 0xFF,   /*  Usage Page (FF01h),                 */
0x09, 0x00,         /*  Usage (00h),                        */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x08,         /*      Report ID (8),                  */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x09, 0x00,         /*      Usage (00h),                    */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x05,         /*      Report Count (5),               */
0xB1, 0x02,         /*      Feature (Variable),             */
0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_star01_fixed1_size =
			sizeof(uclogic_rdesc_star01_fixed1_arr);

/* Fixed STAR01 tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_star01_fixed2_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x06,         /*  Usage (Keyboard),                   */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x03,         /*      Report ID (3),                  */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x25, 0x01,         /*      Logical Maximum (1),            */
0x75, 0x01,         /*      Report Size (1),                */
0x95, 0x08,         /*      Report Count (8),               */
0x81, 0x02,         /*      Input (Variable),               */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0x00,         /*      Usage Minimum (None),           */
0x29, 0xFF,         /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x06,         /*      Report Count (6),               */
0x81, 0x00,         /*      Input,                          */
0xC0,               /*  End Collection,                     */
0x05, 0x0C,         /*  Usage Page (Consumer),              */
0x09, 0x01,         /*  Usage (Consumer Control),           */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x04,         /*      Report ID (4),                  */
0x19, 0x00,         /*      Usage Minimum (00h),            */
0x2A, 0x3C, 0x02,   /*      Usage Maximum (AC Format),      */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x26, 0x3C, 0x02,   /*      Logical Maximum (572),          */
0x95, 0x01,         /*      Report Count (1),               */
0x75, 0x10,         /*      Report Size (16),               */
0x81, 0x00,         /*      Input,                          */
0xC0,               /*  End Collection,                     */
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x80,         /*  Usage (Sys Control),                */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x05,         /*      Report ID (5),                  */
0x19, 0x81,         /*      Usage Minimum (Sys Power Down), */
0x29, 0x83,         /*      Usage Maximum (Sys Wake Up),    */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x25, 0x01,         /*      Logical Maximum (1),            */
0x75, 0x01,         /*      Report Size (1),                */
0x95, 0x03,         /*      Report Count (3),               */
0x81, 0x02,         /*      Input (Variable),               */
0x95, 0x05,         /*      Report Count (5),               */
0x81, 0x01,         /*      Input (Constant),               */
0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_star01_fixed2_size =
			sizeof(uclogic_rdesc_star01_fixed2_arr);			
			



/* Fixed ART22E tablet report descriptor, interface 0 (stylus) */
__u8 uclogic_rdesc_art22e_fixed0_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),             */
0x09, 0x02,                     /*  Usage (Pen),                        */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x07,                     /*      Report ID (7),                  */
0x09, 0x20,                     /*      Usage (Stylus),                 */
0xA0,                           /*      Collection (Physical),          */
0x14,                           /*          Logical Minimum (0),        */
0x25, 0x01,                     /*          Logical Maximum (1),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x09, 0x42,                     /*          Usage (Tip Switch),         */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x09, 0x46,                     /*          Usage (Tablet Pick),        */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x09, 0x32,                     /*          Usage (In Range),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x75, 0x10,                     /*          Report Size (16),           */
0x95, 0x01,                     /*          Report Count (1),           */
0xA4,                           /*          Push,                       */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x65, 0x13,                     /*          Unit (Inch),                */
0x55, 0xFD,                     /*          Unit Exponent (-3),         */
0x34,                           /*          Physical Minimum (0),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x27, 0x11, 0x95, 0x00, 0x00,   /*          Logical Maximum (38161),    */
0x47, 0x5C, 0x49, 0x00, 0x00,   /*          Physical Maximum (18780),   */
0x81, 0x02,                     /*          Input (Variable),           */
0x09, 0x31,                     /*          Usage (Y),                  */
0x27, 0xD2, 0x53, 0x00, 0x00,   /*          Logical Maximum (21458),    */
0x47, 0x40, 0x29, 0x00, 0x00,   /*          Physical Maximum (10560),   */
0x81, 0x02,                     /*          Input (Variable),           */
0xB4,                           /*          Pop,                        */
0x09, 0x30,                     /*          Usage (Tip Pressure),       */
0x27, 0xFF, 0x07, 0x00, 0x00,   /*          Logical Maximum (2047),     */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x05, 0x01,                     /*  Usage Page (Desktop),               */
0x09, 0x07,                     /*  Usage (Keypad),                     */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0xF7,                     /*      Report ID (247),                */
0x05, 0x0D,                     /*      Usage Page (Digitizer),         */
0x09, 0x39,                     /*      Usage (Tablet Function Keys),   */
0xA0,                           /*      Collection (Physical),          */
0x05, 0x09,                     /*          Usage Page (Button),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x95, 0x18,                     /*          Report Count (24),          */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x19, 0x01,                     /*          Usage Minimum (01h),        */
0x29, 0x08,                     /*          Usage Maximum (08h),        */
0x95, 0x08,                     /*          Report Count (8),           */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_art22e_fixed0_size =
			sizeof(uclogic_rdesc_art22e_fixed0_arr);

/* Fixed ART22E tablet report descriptor, interface 1 (mouse) */
__u8 uclogic_rdesc_art22e_fixed1_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),                   */
0x09, 0x02,         /*  Usage (Mouse),                          */
0xA1, 0x01,         /*  Collection (Application),               */
0x09, 0x01,         /*      Usage (Pointer),                    */
0xA1, 0x00,         /*      Collection (Physical),              */
0x85, 0x01,         /*          Report ID (1),                  */
0x05, 0x09,         /*          Usage Page (Button),            */
0x19, 0x01,         /*          Usage Minimum (01h),            */
0x29, 0x05,         /*          Usage Maximum (05h),            */
0x95, 0x05,         /*          Report Count (5),               */
0x75, 0x01,         /*          Report Size (1),                */
0x15, 0x00,         /*          Logical Minimum (0),            */
0x25, 0x01,         /*          Logical Maximum (1),            */
0x81, 0x02,         /*          Input (Variable),               */
0x95, 0x03,         /*          Report Count (3),               */
0x81, 0x01,         /*          Input (Constant),               */
0x05, 0x01,         /*          Usage Page (Desktop),           */
0x09, 0x30,         /*          Usage (X),                      */
0x09, 0x31,         /*          Usage (Y),                      */
0x95, 0x02,         /*          Report Count (2),               */
0x75, 0x10,         /*          Report Size (16),               */
0x16, 0x00, 0x80,   /*          Logical Minimum (-32768),       */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),        */
0x81, 0x06,         /*          Input (Variable, Relative),     */
0x09, 0x38,         /*          Usage (Wheel),                  */
0x15, 0x81,         /*          Logical Minimum (-127),         */
0x25, 0x7F,         /*          Logical Maximum (127),          */
0x95, 0x01,         /*          Report Count (1),               */
0x75, 0x08,         /*          Report Size (8),                */
0x81, 0x06,         /*          Input (Variable, Relative),     */
0x05, 0x0C,         /*          Usage Page (Consumer),          */
0x0A, 0x38, 0x02,   /*          Usage (AC Pan),                 */
0x95, 0x01,         /*          Report Count (1),               */
0x75, 0x08,         /*          Report Size (8),                */
0x81, 0x06,         /*          Input (Variable, Relative),     */
0xC0,               /*      End Collection,                     */
0xC0,               /*  End Collection,                         */
0x06, 0x01, 0xFF,   /*  Usage Page (FF01h),                     */
0x09, 0x00,         /*  Usage (00h),                            */
0xA1, 0x01,         /*  Collection (Application),               */
0x85, 0x08,         /*      Report ID (8),                      */
0x15, 0x00,         /*      Logical Minimum (0),                */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),              */
0x09, 0x00,         /*      Usage (00h),                        */
0x75, 0x08,         /*      Report Size (8),                    */
0x95, 0x05,         /*      Report Count (5),                   */
0xB1, 0x02,         /*      Feature (Variable),                 */
0xC0,               /*  End Collection,                         */
0x05, 0x0D,         /*  Usage Page (Digitizer),                 */
0x09, 0x02,         /*  Usage (Pen),                            */
0xA1, 0x01,         /*  Collection (Application),               */
0x85, 0x0A,         /*      Report ID (10),                     */
0x09, 0x20,         /*      Usage (Stylus),                     */
0xA1, 0x00,         /*      Collection (Physical),              */
0x09, 0x42,         /*          Usage (Tip Switch),             */
0x09, 0x44,         /*          Usage (Barrel Switch),          */
0x09, 0x45,         /*          Usage (Eraser),                 */
0x09, 0x3C,         /*          Usage (Invert),                 */
0x09, 0x43,         /*          Usage (Secondary Tip Switch),   */
0x09, 0x44,         /*          Usage (Barrel Switch),          */
0x15, 0x00,         /*          Logical Minimum (0),            */
0x25, 0x01,         /*          Logical Maximum (1),            */
0x75, 0x01,         /*          Report Size (1),                */
0x95, 0x06,         /*          Report Count (6),               */
0x81, 0x02,         /*          Input (Variable),               */
0x09, 0x32,         /*          Usage (In Range),               */
0x75, 0x01,         /*          Report Size (1),                */
0x95, 0x01,         /*          Report Count (1),               */
0x81, 0x02,         /*          Input (Variable),               */
0x81, 0x03,         /*          Input (Constant, Variable),     */
0x05, 0x01,         /*          Usage Page (Desktop),           */
0x09, 0x30,         /*          Usage (X),                      */
0x09, 0x31,         /*          Usage (Y),                      */
0x55, 0x0D,         /*          Unit Exponent (13),             */
0x65, 0x33,         /*          Unit (Inch^3),                  */
0x26, 0x00, 0x08,   /*          Logical Maximum (2048),         */
0x35, 0x00,         /*          Physical Minimum (0),           */
0x46, 0x00, 0x08,   /*          Physical Maximum (2048),        */
0x75, 0x10,         /*          Report Size (16),               */
0x95, 0x02,         /*          Report Count (2),               */
0x81, 0x02,         /*          Input (Variable),               */
0x05, 0x0D,         /*          Usage Page (Digitizer),         */
0x09, 0x30,         /*          Usage (Tip Pressure),           */
0x26, 0xFF, 0x07,   /*          Logical Maximum (2047),         */
0x75, 0x10,         /*          Report Size (16),               */
0x95, 0x01,         /*          Report Count (1),               */
0x81, 0x02,         /*          Input (Variable),               */
0xC0,               /*      End Collection,                     */
0xC0,               /*  End Collection,                         */
0x05, 0x01          /*  Usage Page (Desktop)                    */
};

const size_t uclogic_rdesc_art22e_fixed1_size =
			sizeof(uclogic_rdesc_art22e_fixed1_arr);

/* Fixed ART22E tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_art22e_fixed2_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),                   */
0x09, 0x06,         /*  Usage (Keyboard),                       */
0xA1, 0x01,         /*  Collection (Application),               */
0x85, 0x03,         /*      Report ID (3),                      */
0x05, 0x07,         /*      Usage Page (Keyboard),              */
0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol),     */
0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),       */
0x15, 0x00,         /*      Logical Minimum (0),                */
0x25, 0x01,         /*      Logical Maximum (1),                */
0x75, 0x01,         /*      Report Size (1),                    */
0x95, 0x08,         /*      Report Count (8),                   */
0x81, 0x02,         /*      Input (Variable),                   */
0x05, 0x07,         /*      Usage Page (Keyboard),              */
0x19, 0x00,         /*      Usage Minimum (None),               */
0x29, 0xFF,         /*      Usage Maximum (FFh),                */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),              */
0x75, 0x08,         /*      Report Size (8),                    */
0x95, 0x06,         /*      Report Count (6),                   */
0x81, 0x00,         /*      Input,                              */
0xC0,               /*  End Collection,                         */
0x05, 0x0C,         /*  Usage Page (Consumer),                  */
0x09, 0x01,         /*  Usage (Consumer Control),               */
0xA1, 0x01,         /*  Collection (Application),               */
0x85, 0x04,         /*      Report ID (4),                      */
0x19, 0x01,         /*      Usage Minimum (Consumer Control),   */
0x2A, 0x9C, 0x02,   /*      Usage Maximum (AC Distribute Vert), */
0x15, 0x01,         /*      Logical Minimum (1),                */
0x26, 0x9C, 0x02,   /*      Logical Maximum (668),              */
0x95, 0x01,         /*      Report Count (1),                   */
0x75, 0x10,         /*      Report Size (16),                   */
0x81, 0x00,         /*      Input,                              */
0xC0,               /*  End Collection,                         */
0x05, 0x01,         /*  Usage Page (Desktop),                   */
0x09, 0x80,         /*  Usage (Sys Control),                    */
0xA1, 0x01,         /*  Collection (Application),               */
0x85, 0x05,         /*      Report ID (5),                      */
0x19, 0x81,         /*      Usage Minimum (Sys Power Down),     */
0x29, 0x83,         /*      Usage Maximum (Sys Wake Up),        */
0x15, 0x00,         /*      Logical Minimum (0),                */
0x25, 0x01,         /*      Logical Maximum (1),                */
0x75, 0x01,         /*      Report Size (1),                    */
0x95, 0x03,         /*      Report Count (3),                   */
0x81, 0x02,         /*      Input (Variable),                   */
0x95, 0x05,         /*      Report Count (5),                   */
0x81, 0x01,         /*      Input (Constant),                   */
0xC0                /*  End Collection                          */
};

const size_t uclogic_rdesc_art22e_fixed2_size =
			sizeof(uclogic_rdesc_art22e_fixed2_arr);			
			



			
/* Fixed ART156PRO tablet report descriptor, interface 0 (stylus) */
__u8 uclogic_rdesc_art156pro_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x09,         /*      Report ID (9),                  */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x03,         /*          Usage Maximum (03h),        */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x95, 0x03,         /*          Report Count (3),           */
0x75, 0x01,         /*          Report Size (1),            */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0x05, 0x0D,         /*          Usage Page (Digitizer),     */
0x09, 0x30,         /*          Usage (Tip Pressure),       */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x85, 0x01,         /*          Report ID (1),              */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x05,         /*          Usage Maximum (05h),        */
0x95, 0x05,         /*          Report Count (5),           */
0x75, 0x01,         /*          Report Size (1),            */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x03,         /*          Report Count (3),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x16, 0x00, 0x80,   /*          Logical Minimum (-32768),   */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x81, 0x06,         /*          Input (Variable, Relative), */
0x09, 0x38,         /*          Usage (Wheel),              */
0x15, 0x81,         /*          Logical Minimum (-127),     */
0x25, 0x7F,         /*          Logical Maximum (127),      */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x08,         /*          Report Size (8),            */
0x81, 0x06,         /*          Input (Variable, Relative), */
0x05, 0x0C,         /*          Usage Page (Consumer),      */
0x0A, 0x38, 0x02,   /*          Usage (AC Pan),             */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x08,         /*          Report Size (8),            */
0x81, 0x06,         /*          Input (Variable, Relative), */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x06,         /*  Usage (Keyboard),                   */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x06,         /*      Report ID (6),                  */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x25, 0x01,         /*      Logical Maximum (1),            */
0x75, 0x01,         /*      Report Size (1),                */
0x95, 0x08,         /*      Report Count (8),               */
0x81, 0x02,         /*      Input (Variable),               */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0x00,         /*      Usage Minimum (None),           */
0x29, 0xFF,         /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x06,         /*      Report Count (6),               */
0x81, 0x00,         /*      Input,                          */
0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_art156pro_fixed0_size =
			sizeof(uclogic_rdesc_art156pro_fixed0_arr);

/* Fixed ART156PRO tablet report descriptor, interface 1 (mouse) */
__u8 uclogic_rdesc_art156pro_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),                 */
0x09, 0x02,                     /*  Usage (Pen),                            */
0xA1, 0x01,                     /*  Collection (Application),               */
0x85, 0x07,                     /*      Report ID (7),                      */
0x09, 0x20,                     /*      Usage (Stylus),                     */
0xA1, 0x00,                     /*      Collection (Physical),              */
0x09, 0x42,                     /*          Usage (Tip Switch),             */
0x09, 0x44,                     /*          Usage (Barrel Switch),          */
0x09, 0x46,                     /*          Usage (Tablet Pick),            */
0x09, 0x3C,                     /*          Usage (Invert),                 */
0x15, 0x00,                     /*          Logical Minimum (0),            */
0x25, 0x01,                     /*          Logical Maximum (1),            */
0x75, 0x01,                     /*          Report Size (1),                */
0x95, 0x04,                     /*          Report Count (4),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x95, 0x01,                     /*          Report Count (1),               */
0x81, 0x03,                     /*          Input (Constant, Variable),     */
0x09, 0x32,                     /*          Usage (In Range),               */
0x95, 0x01,                     /*          Report Count (1),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x95, 0x02,                     /*          Report Count (2),               */
0x81, 0x03,                     /*          Input (Constant, Variable),     */
0x75, 0x10,                     /*          Report Size (16),               */
0x95, 0x01,                     /*          Report Count (1),               */
0x35, 0x00,                     /*          Physical Minimum (0),           */
0xA4,                           /*          Push,                           */
0x05, 0x01,                     /*          Usage Page (Desktop),           */
0x09, 0x30,                     /*          Usage (X),                      */
0x65, 0x13,                     /*          Unit (Inch),                    */
0x55, 0x0D,                     /*          Unit Exponent (13),             */
0x46, 0xE4, 0x34,               /*          Physical Maximum (13540),       */
0x27, 0x73, 0x86, 0x00, 0x00,   /*          Logical Maximum (34419),        */
0x81, 0x02,                     /*          Input (Variable),               */
0x09, 0x31,                     /*          Usage (Y),                      */
0x46, 0xC4, 0x1D,               /*          Physical Maximum (7620),        */
0x26, 0x05, 0x4C,               /*          Logical Maximum (19461),        */
0x81, 0x02,                     /*          Input (Variable),               */
0xB4,                           /*          Pop,                            */
0x09, 0x30,                     /*          Usage (Tip Pressure),           */
0x45, 0x00,                     /*          Physical Maximum (0),           */
0x26, 0xFF, 0x1F,               /*          Logical Maximum (8191),         */
0x81, 0x42,                     /*          Input (Variable, Null State),   */
0x09, 0x3D,                     /*          Usage (X Tilt),                 */
0x15, 0x81,                     /*          Logical Minimum (-127),         */
0x25, 0x7F,                     /*          Logical Maximum (127),          */
0x75, 0x08,                     /*          Report Size (8),                */
0x95, 0x01,                     /*          Report Count (1),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x09, 0x3E,                     /*          Usage (Y Tilt),                 */
0x15, 0x81,                     /*          Logical Minimum (-127),         */
0x25, 0x7F,                     /*          Logical Maximum (127),          */
0x81, 0x02,                     /*          Input (Variable),               */
0xC0,                           /*      End Collection,                     */
0xC0,                           /*  End Collection,                         */
0x06, 0x03, 0xFF,               /*  Usage Page (FF03h),                     */
0x09, 0x00,                     /*  Usage (00h),                            */
0xA1, 0x01,                     /*  Collection (Application),               */
0x85, 0x0B,                     /*      Report ID (11),                     */
0x15, 0x00,                     /*      Logical Minimum (0),                */
0x26, 0xFF, 0x00,               /*      Logical Maximum (255),              */
0x09, 0x00,                     /*      Usage (00h),                        */
0x75, 0x08,                     /*      Report Size (8),                    */
0x95, 0x3F,                     /*      Report Count (63),                  */
0x81, 0x02,                     /*      Input (Variable),                   */
0xC0                            /*  End Collection                          */
};

const size_t uclogic_rdesc_art156pro_fixed1_size =
			sizeof(uclogic_rdesc_art156pro_fixed1_arr);

/* Fixed ART156PRO tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_art156pro_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x09,         /*      Report Count (9),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_art156pro_fixed2_size =
			sizeof(uclogic_rdesc_art156pro_fixed2_arr);			
			



/* Fixed art10sv2 tablet report descriptor, interface 0 (stylus) */
__u8 uclogic_rdesc_art10sv2_fixed0_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),             */
0x09, 0x02,                     /*  Usage (Pen),                        */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x07,                     /*      Report ID (7),                  */
0x09, 0x20,                     /*      Usage (Stylus),                 */
0xA0,                           /*      Collection (Physical),          */
0x14,                           /*          Logical Minimum (0),        */
0x25, 0x01,                     /*          Logical Maximum (1),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x09, 0x42,                     /*          Usage (Tip Switch),         */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x09, 0x46,                     /*          Usage (Tablet Pick),        */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x09, 0x32,                     /*          Usage (In Range),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x75, 0x10,                     /*          Report Size (16),           */
0x95, 0x01,                     /*          Report Count (1),           */
0xA4,                           /*          Push,                       */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x65, 0x13,                     /*          Unit (Inch),                */
0x55, 0xFD,                     /*          Unit Exponent (-3),         */
0x34,                           /*          Physical Minimum (0),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x27, 0xC0, 0x54, 0x00, 0x00,   /*          Logical Maximum (21696),    */
0x47, 0x5D, 0x21, 0x00, 0x00,   /*          Physical Maximum (8541),    */
0x81, 0x02,                     /*          Input (Variable),           */
0x09, 0x31,                     /*          Usage (Y),                  */
0x27, 0xF8, 0x34, 0x00, 0x00,   /*          Logical Maximum (13560),    */
0x47, 0xDA, 0x14, 0x00, 0x00,   /*          Physical Maximum (5338),    */
0x81, 0x02,                     /*          Input (Variable),           */
0xB4,                           /*          Pop,                        */
0x09, 0x30,                     /*          Usage (Tip Pressure),       */
0x27, 0xFF, 0x07, 0x00, 0x00,   /*          Logical Maximum (2047),     */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x05, 0x01,                     /*  Usage Page (Desktop),               */
0x09, 0x06,                     /*  Usage (Keyboard),                   */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x03,                     /*      Report ID (3),                  */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0xE0,                     /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,                     /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x75, 0x01,                     /*      Report Size (1),                */
0x95, 0x08,                     /*      Report Count (8),               */
0x81, 0x02,                     /*      Input (Variable),               */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0x00,                     /*      Usage Minimum (None),           */
0x29, 0xFF,                     /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,               /*      Logical Maximum (255),          */
0x75, 0x08,                     /*      Report Size (8),                */
0x95, 0x06,                     /*      Report Count (6),               */
0x81, 0x00,                     /*      Input,                          */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_art10sv2_fixed0_size =
			sizeof(uclogic_rdesc_art10sv2_fixed0_arr);

/* Fixed art10sv2 tablet report descriptor, interface 1 (mouse) */
__u8 uclogic_rdesc_art10sv2_fixed1_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x85, 0x01,         /*          Report ID (1),              */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x05,         /*          Usage Maximum (05h),        */
0x95, 0x05,         /*          Report Count (5),           */
0x75, 0x01,         /*          Report Size (1),            */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x03,         /*          Report Count (3),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x16, 0x00, 0x80,   /*          Logical Minimum (-32768),   */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x81, 0x06,         /*          Input (Variable, Relative), */
0x09, 0x38,         /*          Usage (Wheel),              */
0x15, 0x81,         /*          Logical Minimum (-127),     */
0x25, 0x7F,         /*          Logical Maximum (127),      */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x08,         /*          Report Size (8),            */
0x81, 0x06,         /*          Input (Variable, Relative), */
0x05, 0x0C,         /*          Usage Page (Consumer),      */
0x0A, 0x38, 0x02,   /*          Usage (AC Pan),             */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x08,         /*          Report Size (8),            */
0x81, 0x06,         /*          Input (Variable, Relative), */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x06, 0x01, 0xFF,   /*  Usage Page (FF01h),                 */
0x09, 0x00,         /*  Usage (00h),                        */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x08,         /*      Report ID (8),                  */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x09, 0x00,         /*      Usage (00h),                    */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x05,         /*      Report Count (5),               */
0xB1, 0x02,         /*      Feature (Variable),             */
0xC0                /*  End Collection                      */

};

const size_t uclogic_rdesc_art10sv2_fixed1_size =
			sizeof(uclogic_rdesc_art10sv2_fixed1_arr);

/* Fixed art10sv2 tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_art10sv2_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0,               /*  End Collection,             */
0x06, 0x01, 0xFF,   /*  Usage Page (FF01h),         */
0x09, 0x00,         /*  Usage (00h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x08,         /*      Report ID (8),          */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x09, 0x00,         /*      Usage (00h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x05,         /*      Report Count (5),       */
0xB1, 0x02,         /*      Feature (Variable),     */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_art10sv2_fixed2_size =
			sizeof(uclogic_rdesc_art10sv2_fixed2_arr);

/* Fixed art22epro tablet report descriptor, interface 0 (keyboard) */
__u8 uclogic_rdesc_art22epro_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x06,         /*  Usage (Keyboard),                   */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x06,         /*      Report ID (6),                  */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x25, 0x01,         /*      Logical Maximum (1),            */
0x75, 0x01,         /*      Report Size (1),                */
0x95, 0x08,         /*      Report Count (8),               */
0x81, 0x02,         /*      Input (Variable),               */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0x00,         /*      Usage Minimum (None),           */
0x29, 0xFF,         /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x06,         /*      Report Count (6),               */
0x81, 0x00,         /*      Input,                          */
0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_art22epro_fixed0_size =
			sizeof(uclogic_rdesc_art22epro_fixed0_arr);

/* Fixed art22epro tablet report descriptor, interface 1 (pen) */
__u8 uclogic_rdesc_art22epro_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),                 */
0x09, 0x02,                     /*  Usage (Pen),                            */
0xA1, 0x01,                     /*  Collection (Application),               */
0x85, 0x07,                     /*      Report ID (7),                      */
0x09, 0x20,                     /*      Usage (Stylus),                     */
0xA1, 0x00,                     /*      Collection (Physical),              */
0x09, 0x42,                     /*          Usage (Tip Switch),             */
0x09, 0x44,                     /*          Usage (Barrel Switch),          */
0x09, 0x46, 			        /*          Usage (Tablet Pick),    	    */
0x15, 0x00,                     /*          Logical Minimum (0),            */
0x25, 0x01,                     /*          Logical Maximum (1),            */
0x75, 0x01,                     /*          Report Size (1),                */
0x95, 0x03,                     /*          Report Count (3),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x95, 0x02,                     /*          Report Count (2),               */
0x81, 0x03,                     /*          Input (Constant, Variable),     */
0x09, 0x32,                     /*          Usage (In Range),               */
0x95, 0x01,                     /*          Report Count (1),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x95, 0x02,                     /*          Report Count (2),               */
0x81, 0x03,                     /*          Input (Constant, Variable),     */
0x75, 0x10,                     /*          Report Size (16),               */
0x95, 0x01,                     /*          Report Count (1),               */
0x35, 0x00,                     /*          Physical Minimum (0),           */
0xA4,                           /*          Push,                           */
0x05, 0x01,                     /*          Usage Page (Desktop),           */
0x09, 0x30,                     /*          Usage (X),                      */
0x46, 0x4D, 0x49,               /*          Physical Maximum (18765),       */
0x27, 0x2F, 0xBA, 0x00, 0x00,   /*          Logical Maximum (47663),        */
0x81, 0x42,                     /*          Input (Variable, Null State),   */
0x09, 0x31,                     /*          Usage (Y),                      */
0x46, 0x3B, 0x29,               /*          Physical Maximum (10555),       */
0x26, 0xB9, 0x68,               /*          Logical Maximum (26809),        */
0x81, 0x42,                     /*          Input (Variable, Null State),   */
0xB4,                           /*          Pop,                            */
0x09, 0x30,                     /*          Usage (Tip Pressure),           */
0x45, 0x00,                     /*          Physical Maximum (0),           */
0x26, 0xFF, 0x1F,               /*          Logical Maximum (8191),         */
0x81, 0x42,                     /*          Input (Variable, Null State),   */
0x09, 0x3D,                     /*          Usage (X Tilt),                 */
0x15, 0x81,                     /*          Logical Minimum (-127),         */
0x25, 0x7F,                     /*          Logical Maximum (127),          */
0x75, 0x08,                     /*          Report Size (8),                */
0x95, 0x01,                     /*          Report Count (1),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x09, 0x3E,                     /*          Usage (Y Tilt),                 */
0x15, 0x81,                     /*          Logical Minimum (-127),         */
0x25, 0x7F,                     /*          Logical Maximum (127),          */
0x81, 0x02,                     /*          Input (Variable),               */
0xC0,                           /*      End Collection,                     */
0xC0                            /*  End Collection,                         */
};

const size_t uclogic_rdesc_art22epro_fixed1_size =
			sizeof(uclogic_rdesc_art22epro_fixed1_arr);

/* Fixed art2epro tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_art22epro_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x04,         /*      Report ID (4),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_art22epro_fixed2_size =
			sizeof(uclogic_rdesc_art22epro_fixed2_arr);

/* Fixed art156 tablet report descriptor, interface 0 (mouse) */
__u8 uclogic_rdesc_art156_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x09,         /*      Report ID (9),                  */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x03,         /*          Usage Maximum (03h),        */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x95, 0x03,         /*          Report Count (3),           */
0x75, 0x01,         /*          Report Size (1),            */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0x05, 0x0D,         /*          Usage Page (Digitizer),     */
0x09, 0x30,         /*          Usage (Tip Pressure),       */
0x26, 0xFF, 0x1F,   /*          Logical Maximum (8191),     */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0xC0,               /*      End Collection,                 */
0xC0                /*  End Collection,                     */
};

const size_t uclogic_rdesc_art156_fixed0_size =
			sizeof(uclogic_rdesc_art156_fixed0_arr);

/* Fixed art156 tablet report descriptor, interface 1 (pen & buttons) */
__u8 uclogic_rdesc_art156_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),             */
0x09, 0x02,                     /*  Usage (Pen),                        */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x07,                     /*      Report ID (7),                  */
0x09, 0x20,                     /*      Usage (Stylus),                 */
0xA1, 0x00,                     /*      Collection (Physical),          */
0x09, 0x42,                     /*          Usage (Tip Switch),         */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x09, 0x46,                     /*          Usage (Tablet Pick),        */
0x15, 0x00,                     /*          Logical Minimum (0),        */
0x25, 0x01,                     /*          Logical Maximum (1),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x09, 0x32,                     /*          Usage (In Range),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x75, 0x10,                     /*          Report Size (16),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x35, 0x00,                     /*          Physical Minimum (0),       */
0xA4,                           /*          Push,                       */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x65, 0x13,                     /*          Unit (Inch),                */
0x55, 0x0D,                     /*          Unit Exponent (13),         */
0x46, 0xEF, 0x34,               /*          Physical Maximum (13551),   */
0x27, 0x73, 0x86, 0x00, 0x00,   /*          Logical Maximum (34419),    */
0x81, 0x02,                     /*          Input (Variable),           */
0x09, 0x31,                     /*          Usage (Y),                  */
0x46, 0xEE, 0x1D,               /*          Physical Maximum (7662),    */
0x27, 0x05, 0x4C, 0x00, 0x00,   /*          Logical Maximum (19461),    */
0x81, 0x02,                     /*          Input (Variable),           */
0xB4,                           /*          Pop,                        */
0x09, 0x30,                     /*          Usage (Tip Pressure),       */
0x45, 0x00,                     /*          Physical Maximum (0),       */
0x26, 0xFF, 0x1F,               /*          Logical Maximum (8191),     */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x05, 0x0C,                     /*  Usage Page (Consumer),              */
0x09, 0x36,                     /*  Usage (Function Buttons),           */
0xA1, 0x00,                     /*  Collection (Physical),              */
0x85, 0x06,                     /*      Report ID (6),                  */
0x05, 0x09,                     /*      Usage Page (Button),            */
0x19, 0x01,                     /*      Usage Minimum (01h),            */
0x29, 0x20,                     /*      Usage Maximum (20h),            */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x95, 0x20,                     /*      Report Count (32),              */
0x75, 0x01,                     /*      Report Size (1),                */
0x81, 0x02,                     /*      Input (Variable),               */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_art156_fixed1_size =
			sizeof(uclogic_rdesc_art156_fixed1_arr);

/* Fixed art156 tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_art156_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0,               /*  End Collection,             */
0x06, 0x01, 0xFF,   /*  Usage Page (FF01h),         */
0x09, 0x00,         /*  Usage (00h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x08,         /*      Report ID (8),          */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x09, 0x00,         /*      Usage (00h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x05,         /*      Report Count (5),       */
0xB1, 0x02,         /*      Feature (Variable),     */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_art156_fixed2_size =
			sizeof(uclogic_rdesc_art156_fixed2_arr);


/* Fixed art133 tablet report descriptor, interface 0 (mouse) */
__u8 uclogic_rdesc_art133_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x09,         /*      Report ID (9),                  */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x03,         /*          Usage Maximum (03h),        */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x95, 0x03,         /*          Report Count (3),           */
0x75, 0x01,         /*          Report Size (1),            */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0x05, 0x0D,         /*          Usage Page (Digitizer),     */
0x09, 0x30,         /*          Usage (Tip Pressure),       */
0x26, 0xFF, 0x07,   /*          Logical Maximum (2047),     */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0xC0                /*      End Collection,                 */
};

const size_t uclogic_rdesc_art133_fixed0_size =
			sizeof(uclogic_rdesc_art133_fixed0_arr);

/* Fixed art133 tablet report descriptor, interface 1 (pen) */
__u8 uclogic_rdesc_art133_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),             */
0x09, 0x02,                     /*  Usage (Pen),                        */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x07,                     /*      Report ID (7),                  */
0x09, 0x20,                     /*      Usage (Stylus),                 */
0xA1, 0x00,                     /*      Collection (Physical),          */
0x09, 0x42,                     /*          Usage (Tip Switch),         */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x09, 0x46,                     /*          Usage (Tablet Pick),             */
0x15, 0x00,                     /*          Logical Minimum (0),        */
0x25, 0x01,                     /*          Logical Maximum (1),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x09, 0x32,                     /*          Usage (In Range),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x75, 0x10,                     /*          Report Size (16),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x35, 0x00,                     /*          Physical Minimum (0),       */
0xA4,                           /*          Push,                       */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x65, 0x13,                     /*          Unit (Inch),                */
0x55, 0x0D,                     /*          Unit Exponent (13),         */
0x46, 0x2D, 0x2D,               /*          Physical Maximum (11565),   */
0x27, 0xC0, 0x72, 0x00, 0x00,   /*          Logical Maximum (29376),    */
0x81, 0x02,                     /*          Input (Variable),           */
0x09, 0x31,                     /*          Usage (Y),                  */
0x46, 0x69, 0x19,               /*          Physical Maximum (6505),    */
0x27, 0x8C, 0x40, 0x00, 0x00,   /*          Logical Maximum (16524),    */
0x81, 0x02,                     /*          Input (Variable),           */
0xB4,                           /*          Pop,                        */
0x09, 0x30,                     /*          Usage (Tip Pressure),       */
0x45, 0x00,                     /*          Physical Maximum (0),       */
0x26, 0xFF, 0x07,               /*          Logical Maximum (2047),     */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x09, 0x0E,                     /*  Usage (0Eh),                        */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x05,                     /*      Report ID (5),                  */
0x09, 0x23,                     /*      Usage (23h),                    */
0xA1, 0x02,                     /*      Collection (Logical),           */
0x09, 0x52,                     /*          Usage (52h),                */
0x09, 0x53,                     /*          Usage (53h),                */
0x25, 0x0A,                     /*          Logical Maximum (10),       */
0x75, 0x08,                     /*          Report Size (8),            */
0x95, 0x02,                     /*          Report Count (2),           */
0xB1, 0x02,                     /*          Feature (Variable),         */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x05, 0x0C,                     /*  Usage Page (Consumer),              */
0x09, 0x36,                     /*  Usage (Function Buttons),           */
0xA1, 0x00,                     /*  Collection (Physical),              */
0x85, 0x06,                     /*      Report ID (6),                  */
0x05, 0x09,                     /*      Usage Page (Button),            */
0x19, 0x01,                     /*      Usage Minimum (01h),            */
0x29, 0x20,                     /*      Usage Maximum (20h),            */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x95, 0x20,                     /*      Report Count (32),              */
0x75, 0x01,                     /*      Report Size (1),                */
0x81, 0x02,                     /*      Input (Variable),               */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_art133_fixed1_size =
			sizeof(uclogic_rdesc_art133_fixed1_arr);

/* Fixed art133 tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_art133_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0,               /*  End Collection,             */
0x06, 0x01, 0xFF,   /*  Usage Page (FF01h),         */
0x09, 0x00,         /*  Usage (00h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x08,         /*      Report ID (8),          */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x09, 0x00,         /*      Usage (00h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x05,         /*      Report Count (5),       */
0xB1, 0x02,         /*      Feature (Variable),     */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_art133_fixed2_size =
			sizeof(uclogic_rdesc_art133_fixed2_arr);

/* Fixed art16pro tablet report descriptor, interface 0 (keyboard) */
__u8 uclogic_rdesc_art16pro_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x06,         /*  Usage (Keyboard),                   */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x06,         /*      Report ID (6),                  */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x25, 0x01,         /*      Logical Maximum (1),            */
0x75, 0x01,         /*      Report Size (1),                */
0x95, 0x08,         /*      Report Count (8),               */
0x81, 0x02,         /*      Input (Variable),               */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0x00,         /*      Usage Minimum (None),           */
0x29, 0xFF,         /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x06,         /*      Report Count (6),               */
0x81, 0x00,         /*      Input,                          */
0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_art16pro_fixed0_size =
			sizeof(uclogic_rdesc_art16pro_fixed0_arr);

/* Fixed art16pro tablet report descriptor, interface 1 (pen) */
__u8 uclogic_rdesc_art16pro_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),                 */
0x09, 0x02,                     /*  Usage (Pen),                            */
0xA1, 0x01,                     /*  Collection (Application),               */
0x85, 0x07,                     /*      Report ID (7),                      */
0x09, 0x20,                     /*      Usage (Stylus),                     */
0xA1, 0x00,                     /*      Collection (Physical),              */
0x09, 0x42,                     /*          Usage (Tip Switch),             */
0x09, 0x44,                     /*          Usage (Barrel Switch),          */
0x09, 0x46,                     /*          Usage (Tablet Pick),            */
0x15, 0x00,                     /*          Logical Minimum (0),            */
0x25, 0x01,                     /*          Logical Maximum (1),            */
0x75, 0x01,                     /*          Report Size (1),                */
0x95, 0x03,                     /*          Report Count (3),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x95, 0x02,                     /*          Report Count (2),               */
0x81, 0x03,                     /*          Input (Constant, Variable),     */
0x09, 0x32,                     /*          Usage (In Range),               */
0x95, 0x01,                     /*          Report Count (1),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x95, 0x02,                     /*          Report Count (2),               */
0x81, 0x03,                     /*          Input (Constant, Variable),     */
0x75, 0x10,                     /*          Report Size (16),               */
0x95, 0x01,                     /*          Report Count (1),               */
0x35, 0x00,                     /*          Physical Minimum (0),           */
0xA4,                           /*          Push,                           */
0x05, 0x01,                     /*          Usage Page (Desktop),           */
0x09, 0x30,                     /*          Usage (X),                      */
0x46, 0xEF, 0x34,               /*          Physical Maximum (13551),       */
0x27, 0x73, 0x86, 0x00, 0x00,   /*          Logical Maximum (34419),        */
0x81, 0x42,                     /*          Input (Variable, Null State),   */
0x09, 0x31,                     /*          Usage (Y),                      */
0x46, 0xEE, 0x1D,               /*          Physical Maximum (7662),        */
0x26, 0x05, 0x4C,               /*          Logical Maximum (19461),        */
0x81, 0x42,                     /*          Input (Variable, Null State),   */
0xB4,                           /*          Pop,                            */
0x09, 0x30,                     /*          Usage (Tip Pressure),           */
0x45, 0x00,                     /*          Physical Maximum (0),           */
0x26, 0xFF, 0x1F,               /*          Logical Maximum (8191),         */
0x81, 0x42,                     /*          Input (Variable, Null State),   */
0x09, 0x3D,                     /*          Usage (X Tilt),                 */
0x15, 0x81,                     /*          Logical Minimum (-127),         */
0x25, 0x7F,                     /*          Logical Maximum (127),          */
0x75, 0x08,                     /*          Report Size (8),                */
0x95, 0x01,                     /*          Report Count (1),               */
0x81, 0x02,                     /*          Input (Variable),               */
0x09, 0x3E,                     /*          Usage (Y Tilt),                 */
0x15, 0x81,                     /*          Logical Minimum (-127),         */
0x25, 0x7F,                     /*          Logical Maximum (127),          */
0x81, 0x02,                     /*          Input (Variable),               */
0xC0,                           /*      End Collection,                     */
0xC0                            /*  End Collection,                         */
};

const size_t uclogic_rdesc_art16pro_fixed1_size =
			sizeof(uclogic_rdesc_art16pro_fixed1_arr);

/* Fixed art16pro tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_art16pro_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x09,         /*      Report Count (9),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x09,         /*      Report Count (9),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0,               /*  End Collection,             */
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x04,         /*      Report ID (4),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_art16pro_fixed2_size =
			sizeof(uclogic_rdesc_art16pro_fixed2_arr);



/* Fixed star06 tablet report descriptor, interface 0 (mouse) */
__u8 uclogic_rdesc_star06_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x09,         /*      Report ID (9),                  */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x03,         /*          Usage Maximum (03h),        */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x95, 0x03,         /*          Report Count (3),           */
0x75, 0x01,         /*          Report Size (1),            */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0x05, 0x0D,         /*          Usage Page (Digitizer),     */
0x09, 0x30,         /*          Usage (Tip Pressure),       */
0x26, 0xFF, 0x1F,   /*          Logical Maximum (8191),     */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x00,         /*  Usage (00h),                        */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x04,         /*      Report ID (4),                  */
0xA1, 0x00,         /*      Collection (Physical),          */
0x26, 0xFF, 0x00,   /*          Logical Maximum (255),      */
0x09, 0x00,         /*          Usage (00h),                */
0x75, 0x08,         /*          Report Size (8),            */
0x95, 0x07,         /*          Report Count (7),           */
0xB1, 0x02,         /*          Feature (Variable),         */
0xC0,               /*      End Collection,                 */
0xC0                /*  End Collection                      */

};

const size_t uclogic_rdesc_star06_fixed0_size =
			sizeof(uclogic_rdesc_star06_fixed0_arr);

/* Fixed star06 tablet report descriptor, interface 1 (pen buttones keyboard) */
__u8 uclogic_rdesc_star06_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),             */
0x09, 0x01,                     /*  Usage (Digitizer),                  */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x07,                     /*      Report ID (7),                  */
0x09, 0x20,                     /*      Usage (Stylus),                 */
0xA1, 0x00,                     /*      Collection (Physical),          */
0x09, 0x42,                     /*          Usage (Tip Switch),         */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x09, 0x46,                     /*          Usage (Tablet Pick),         */
0x15, 0x00,                     /*          Logical Minimum (0),        */
0x25, 0x01,                     /*          Logical Maximum (1),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x09, 0x32,                     /*          Usage (In Range),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x75, 0x10,                     /*          Report Size (16),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x35, 0x00,                     /*          Physical Minimum (0),       */
0xA4,                           /*          Push,                       */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x65, 0x13,                     /*          Unit (Inch),                */
0x55, 0x0D,                     /*          Unit Exponent (13),         */
0x46, 0x34, 0x03,               /*          Physical Maximum (820),     */
0x27, 0x70, 0xC6, 0x00, 0x00,   /*          Logical Maximum (50800),    */
0x81, 0x02,                     /*          Input (Variable),           */
0x09, 0x31,                     /*          Usage (Y),                  */
0x46, 0x4D, 0x04,               /*          Physical Maximum (1101),    */
0x27, 0x10, 0x77, 0x00, 0x00,   /*          Logical Maximum (30480),    */
0x81, 0x02,                     /*          Input (Variable),           */
0xB4,                           /*          Pop,                        */
0x09, 0x30,                     /*          Usage (Tip Pressure),       */
0x45, 0x00,                     /*          Physical Maximum (0),       */
0x26, 0xFF, 0x1F,               /*          Logical Maximum (8191),     */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x09, 0x0E,                     /*  Usage (0Eh),                        */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x05,                     /*      Report ID (5),                  */
0x09, 0x23,                     /*      Usage (23h),                    */
0xA1, 0x02,                     /*      Collection (Logical),           */
0x09, 0x52,                     /*          Usage (52h),                */
0x09, 0x53,                     /*          Usage (53h),                */
0x25, 0x0A,                     /*          Logical Maximum (10),       */
0x75, 0x08,                     /*          Report Size (8),            */
0x95, 0x02,                     /*          Report Count (2),           */
0xB1, 0x02,                     /*          Feature (Variable),         */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x05, 0x0C,                     /*  Usage Page (Consumer),              */
0x09, 0x36,                     /*  Usage (Function Buttons),           */
0xA1, 0x00,                     /*  Collection (Physical),              */
0x85, 0x06,                     /*      Report ID (6),                  */
0x05, 0x09,                     /*      Usage Page (Button),            */
0x19, 0x01,                     /*      Usage Minimum (01h),            */
0x29, 0x20,                     /*      Usage Maximum (20h),            */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x95, 0x20,                     /*      Report Count (32),              */
0x75, 0x01,                     /*      Report Size (1),                */
0x81, 0x02,                     /*      Input (Variable),               */
0xC0,                           /*  End Collection,                     */
0x05, 0x01,                     /*  Usage Page (Desktop),               */
0x09, 0x06,                     /*  Usage (Keyboard),                   */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x03,                     /*      Report ID (3),                  */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0xE0,                     /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,                     /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x75, 0x01,                     /*      Report Size (1),                */
0x95, 0x08,                     /*      Report Count (8),               */
0x81, 0x02,                     /*      Input (Variable),               */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0x00,                     /*      Usage Minimum (None),           */
0x29, 0xFF,                     /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,               /*      Logical Maximum (255),          */
0x75, 0x08,                     /*      Report Size (8),                */
0x95, 0x06,                     /*      Report Count (6),               */
0x81, 0x00,                     /*      Input,                          */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_star06_fixed1_size =
			sizeof(uclogic_rdesc_star06_fixed1_arr);

/* Fixed star06 tablet report descriptor, interface 2 (frame buttons) */
__u8 uclogic_rdesc_star06_fixed2_arr[] = {
0x09, 0x36,                     /*  Usage (Function Buttons),           */
0xA1, 0x00,                     /*  Collection (Physical),              */
0x85, 0x06,                     /*      Report ID (6),                  */
0x05, 0x09,                     /*      Usage Page (Button),            */
0x19, 0x01,                     /*      Usage Minimum (01h),            */
0x29, 0x20,                     /*      Usage Maximum (20h),            */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x95, 0x20,                     /*      Report Count (32),              */
0x75, 0x01,                     /*      Report Size (1),                */
0x81, 0x02,                     /*      Input (Variable),               */
0xC0,                           /*  End Collection,                     */
0x05, 0x01,                     /*  Usage Page (Desktop),               */
0x09, 0x06,                     /*  Usage (Keyboard),                   */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x03,                     /*      Report ID (3),                  */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0xE0,                     /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,                     /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x75, 0x01,                     /*      Report Size (1),                */
0x95, 0x08,                     /*      Report Count (8),               */
0x81, 0x02,                     /*      Input (Variable),               */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0x00,                     /*      Usage Minimum (None),           */
0x29, 0xFF,                     /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,               /*      Logical Maximum (255),          */
0x75, 0x08,                     /*      Report Size (8),                */
0x95, 0x06,                     /*      Report Count (6),               */
0x81, 0x00,                     /*      Input,                          */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_star06_fixed2_size =
			sizeof(uclogic_rdesc_star06_fixed2_arr);
			
/* Fixed report descriptor for XP-Pen Deco 01 frame controls */
const __u8 uclogic_rdesc_xppen_deco01_frame_arr[] = {
	0x05, 0x01, /*  Usage Page (Desktop),               */
	0x09, 0x07, /*  Usage (Keypad),                     */
	0xA1, 0x01, /*  Collection (Application),           */
	0x85, 0x06, /*      Report ID (6),                  */
	0x14,       /*      Logical Minimum (0),            */
	0x25, 0x01, /*      Logical Maximum (1),            */
	0x75, 0x01, /*      Report Size (1),                */
	0x05, 0x0D, /*      Usage Page (Digitizer),         */
	0x09, 0x39, /*      Usage (Tablet Function Keys),   */
	0xA0,       /*      Collection (Physical),          */
	0x05, 0x09, /*          Usage Page (Button),        */
	0x19, 0x01, /*          Usage Minimum (01h),        */
	0x29, 0x08, /*          Usage Maximum (08h),        */
	0x95, 0x08, /*          Report Count (8),           */
	0x81, 0x02, /*          Input (Variable),           */
	0x05, 0x0D, /*          Usage Page (Digitizer),     */
	0x09, 0x44, /*          Usage (Barrel Switch),      */
	0x95, 0x01, /*          Report Count (1),           */
	0x81, 0x02, /*          Input (Variable),           */
	0x05, 0x01, /*          Usage Page (Desktop),       */
	0x09, 0x30, /*          Usage (X),                  */
	0x09, 0x31, /*          Usage (Y),                  */
	0x95, 0x02, /*          Report Count (2),           */
	0x81, 0x02, /*          Input (Variable),           */
	0x95, 0x15, /*          Report Count (21),          */
	0x81, 0x01, /*          Input (Constant),           */
	0xC0,       /*      End Collection,                 */
	0xC0        /*  End Collection                      */

};

const size_t uclogic_rdesc_xppen_deco01_frame_size =
			sizeof(uclogic_rdesc_xppen_deco01_frame_arr);


/* Fixed report descriptor for XP-Pen Deco 01mod frame controls */
const __u8 uclogic_rdesc_xppen_deco01mod_frame_arr[] = {
	0x05, 0x01, /*  Usage Page (Desktop),               */
	0x09, 0x07, /*  Usage (Keypad),                     */
	0xA1, 0x01, /*  Collection (Application),           */
	0x85, 0x06, /*      Report ID (6),                  */
	0x14,       /*      Logical Minimum (0),            */
	0x25, 0x01, /*      Logical Maximum (1),            */
	0x75, 0x01, /*      Report Size (1),                */
	0x05, 0x0D, /*      Usage Page (Digitizer),         */
	0x09, 0x39, /*      Usage (Tablet Function Keys),   */
	0xA0,       /*      Collection (Physical),          */
	0x05, 0x09, /*          Usage Page (Button),        */
	0x19, 0x01, /*          Usage Minimum (01h),        */
	0x29, 0x08, /*          Usage Maximum (08h),        */
	0x95, 0x08, /*          Report Count (8),           */
	0x81, 0x02, /*          Input (Variable),           */
	0x05, 0x0D, /*          Usage Page (Digitizer),     */
	0x09, 0x44, /*          Usage (Barrel Switch),      */
	0x95, 0x01, /*          Report Count (1),           */
	0x81, 0x02, /*          Input (Variable),           */
	0x05, 0x01, /*          Usage Page (Desktop),       */
	0x09, 0x30, /*          Usage (X),                  */
	0x09, 0x31, /*          Usage (Y),                  */
	0x95, 0x02, /*          Report Count (2),           */
	0x81, 0x02, /*          Input (Variable),           */
	0x95, 0x15, /*          Report Count (21),          */
	0x81, 0x01, /*          Input (Constant),           */
	0xC0,       /*      End Collection,                 */
	0xC0,       /*  End Collection                      */
	0x05, 0x01,                     /*  Usage Page (Desktop),               */
	0x09, 0x06,                     /*  Usage (Keyboard),                   */
	0xA1, 0x01,                     /*  Collection (Application),           */
	0x85, 0x03,                     /*      Report ID (3),                  */
	0x05, 0x07,                     /*      Usage Page (Keyboard),          */
	0x19, 0xE0,                     /*      Usage Minimum (KB Leftcontrol), */
	0x29, 0xE7,                     /*      Usage Maximum (KB Right GUI),   */
	0x15, 0x00,                     /*      Logical Minimum (0),            */
	0x25, 0x01,                     /*      Logical Maximum (1),            */
	0x75, 0x01,                     /*      Report Size (1),                */
	0x95, 0x08,                     /*      Report Count (8),               */
	0x81, 0x02,                     /*      Input (Variable),               */
	0x05, 0x07,                     /*      Usage Page (Keyboard),          */
	0x19, 0x00,                     /*      Usage Minimum (None),           */
	0x29, 0xFF,                     /*      Usage Maximum (FFh),            */
	0x26, 0xFF, 0x00,               /*      Logical Maximum (255),          */
	0x75, 0x08,                     /*      Report Size (8),                */
	0x95, 0x06,                     /*      Report Count (6),               */
	0x81, 0x00,                     /*      Input,                          */
	0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_xppen_deco01mod_frame_size =
			sizeof(uclogic_rdesc_xppen_deco01mod_frame_arr);

			
/* Fixed deco01 tablet report descriptor, interface 0 (mouse) */
__u8 uclogic_rdesc_deco01_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x08,         /*      Report ID (8),                  */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x03,         /*          Usage Maximum (03h),        */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x95, 0x03,         /*          Report Count (3),           */
0x75, 0x01,         /*          Report Size (1),            */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x09, 0x38,         /*          Usage (Wheel),              */
0x09, 0x00,         /*          Usage (00h),                */
0x15, 0x81,         /*          Logical Minimum (-127),     */
0x25, 0x7F,         /*          Logical Maximum (127),      */
0x75, 0x08,         /*          Report Size (8),            */
0x95, 0x04,         /*          Report Count (4),           */
0x81, 0x06,         /*          Input (Variable, Relative), */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x00,         /*  Usage (00h),                        */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x04,         /*      Report ID (4),                  */
0xA1, 0x00,         /*      Collection (Physical),          */
0x26, 0xFF, 0x00,   /*          Logical Maximum (255),      */
0x09, 0x00,         /*          Usage (00h),                */
0x75, 0x08,         /*          Report Size (8),            */
0x95, 0x07,         /*          Report Count (7),           */
0xB1, 0x02,         /*          Feature (Variable),         */
0xC0,               /*      End Collection,                 */
0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_deco01_fixed0_size =
			sizeof(uclogic_rdesc_deco01_fixed0_arr);


/* Fixed deco01 tablet report descriptor, interface 1 (stylus) */
__u8 uclogic_rdesc_deco01_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),             */
0x09, 0x02,                     /*  Usage (Pen),                        */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x07,                     /*      Report ID (7),                  */
0x09, 0x20,                     /*      Usage (Stylus),                 */
0xA0,                           /*      Collection (Physical),          */
0x14,                           /*          Logical Minimum (0),        */
0x25, 0x01,                     /*          Logical Maximum (1),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x09, 0x42,                     /*          Usage (Tip Switch),         */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x09, 0x46,                     /*          Usage (Tablet Pick),        */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x09, 0x32,                     /*          Usage (In Range),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x75, 0x10,                     /*          Report Size (16),           */
0x95, 0x01,                     /*          Report Count (1),           */
0xA4,                           /*          Push,                       */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x65, 0x13,                     /*          Unit (Inch),                */
0x55, 0xFD,                     /*          Unit Exponent (-3),         */
0x34,                           /*          Physical Minimum (0),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x27, 0x38, 0x63, 0x00, 0x00,   /*          Logical Maximum (25400),    */
0x47, 0x10, 0x27, 0x00, 0x00,   /*          Physical Maximum (10000),   */
0x81, 0x02,                     /*          Input (Variable),           */
0x09, 0x31,                     /*          Usage (Y),                  */
0x27, 0x03, 0x3E, 0x00, 0x00,   /*          Logical Maximum (15875),    */
0x47, 0x6A, 0x18, 0x00, 0x00,   /*          Physical Maximum (6250),    */
0x81, 0x02,                     /*          Input (Variable),           */
0xB4,                           /*          Pop,                        */
0x09, 0x30,                     /*          Usage (Tip Pressure),       */
0x27, 0xFF, 0x1F, 0x00, 0x00,   /*          Logical Maximum (8191),     */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x05, 0x01,                     /*  Usage Page (Desktop),               */
0x09, 0x07,                     /*  Usage (Keypad),                     */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x06,                     /*      Report ID (6),                  */
0x14,                           /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x75, 0x01,                     /*      Report Size (1),                */
0x05, 0x0D,                     /*      Usage Page (Digitizer),         */
0x09, 0x39,                     /*      Usage (Tablet Function Keys),   */
0xA0,                           /*      Collection (Physical),          */
0x05, 0x09,                     /*          Usage Page (Button),        */
0x19, 0x01,                     /*          Usage Minimum (01h),        */
0x29, 0x08,                     /*          Usage Maximum (08h),        */
0x95, 0x08,                     /*          Report Count (8),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x05, 0x0D,                     /*          Usage Page (Digitizer),     */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x09, 0x31,                     /*          Usage (Y),                  */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x15,                     /*          Report Count (21),          */
0x81, 0x01,                     /*          Input (Constant),           */
0xC0,                           /*      End Collection,                 */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_deco01_fixed1_size =
			sizeof(uclogic_rdesc_deco01_fixed1_arr);





/* Fixed deco01 tablet report descriptor, interface 2 (param) */
__u8 uclogic_rdesc_deco01_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0                /*  End Collection,             */
};

const size_t uclogic_rdesc_deco01_fixed2_size =
			sizeof(uclogic_rdesc_deco01_fixed2_arr);




/* Fixed deco01v2 tablet report descriptor, interface 0 (keyboard) */
__u8 uclogic_rdesc_deco01v2_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x06,         /*  Usage (Keyboard),                   */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x06,         /*      Report ID (6),                  */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x25, 0x01,         /*      Logical Maximum (1),            */
0x75, 0x01,         /*      Report Size (1),                */
0x95, 0x08,         /*      Report Count (8),               */
0x81, 0x02,         /*      Input (Variable),               */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0x00,         /*      Usage Minimum (None),           */
0x29, 0xFF,         /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x06,         /*      Report Count (6),               */
0x81, 0x00,         /*      Input,                          */
0xC0                /*  End Collection                      */

};

const size_t uclogic_rdesc_deco01v2_fixed0_size =
			sizeof(uclogic_rdesc_deco01v2_fixed0_arr);

/* Fixed deco01v2 tablet report descriptor, interface 1 (stylus) */
__u8 uclogic_rdesc_deco01v2_fixed1_arr[] = {
0x05, 0x0D,         /*  Usage Page (Digitizer),                 */
0x09, 0x02,         /*  Usage (Pen),                            */
0xA1, 0x01,         /*  Collection (Application),               */
0x85, 0x07,         /*      Report ID (7),                      */
0x09, 0x20,         /*      Usage (Stylus),                     */
0xA1, 0x00,         /*      Collection (Physical),              */
0x09, 0x42,         /*          Usage (Tip Switch),             */
0x09, 0x44,         /*          Usage (Barrel Switch),          */
0x09, 0x46,         /*          Usage (Tablet Pick),            */
0x15, 0x00,         /*          Logical Minimum (0),            */
0x25, 0x01,         /*          Logical Maximum (1),            */
0x75, 0x01,         /*          Report Size (1),                */
0x95, 0x03,         /*          Report Count (3),               */
0x81, 0x02,         /*          Input (Variable),               */
0x95, 0x02,         /*          Report Count (2),               */
0x81, 0x03,         /*          Input (Constant, Variable),     */
0x09, 0x32,         /*          Usage (In Range),               */
0x95, 0x01,         /*          Report Count (1),               */
0x81, 0x02,         /*          Input (Variable),               */
0x95, 0x02,         /*          Report Count (2),               */
0x81, 0x03,         /*          Input (Constant, Variable),     */
0x75, 0x10,         /*          Report Size (16),               */
0x95, 0x01,         /*          Report Count (1),               */
0x35, 0x00,         /*          Physical Minimum (0),           */
0xA4,               /*          Push,                           */
0x05, 0x01,         /*          Usage Page (Desktop),           */
0x09, 0x30,         /*          Usage (X),                      */
0x65, 0x13,         /*          Unit (Inch),                    */
0x55, 0x0D,         /*          Unit Exponent (13),             */
0x46, 0x10, 0x27,   /*          Physical Maximum (10000),       */
0x26, 0x38, 0x63,   /*          Logical Maximum (25400),        */
0x81, 0x02,         /*          Input (Variable),               */
0x09, 0x31,         /*          Usage (Y),                      */
0x46, 0x6A, 0x18,   /*          Physical Maximum (6250),        */
0x26, 0x03, 0x3E,   /*          Logical Maximum (15875),        */
0x81, 0x02,         /*          Input (Variable),               */
0xB4,               /*          Pop,                            */
0x09, 0x30,         /*          Usage (Tip Pressure),           */
0x45, 0x00,         /*          Physical Maximum (0),           */
0x26, 0xFF, 0x1F,   /*          Logical Maximum (8191),         */
0x81, 0x42,         /*          Input (Variable, Null State),   */
0x09, 0x3D,         /*          Usage (X Tilt),                 */
0x15, 0x81,         /*          Logical Minimum (-127),         */
0x25, 0x7F,         /*          Logical Maximum (127),          */
0x75, 0x08,         /*          Report Size (8),                */
0x95, 0x01,         /*          Report Count (1),               */
0x81, 0x02,         /*          Input (Variable),               */
0x09, 0x3E,         /*          Usage (Y Tilt),                 */
0x15, 0x81,         /*          Logical Minimum (-127),         */
0x25, 0x7F,         /*          Logical Maximum (127),          */
0x81, 0x02,         /*          Input (Variable),               */
0xC0,               /*      End Collection,                     */
0xC0                /*  End Collection,                         */
};

const size_t uclogic_rdesc_deco01v2_fixed1_size =
			sizeof(uclogic_rdesc_deco01v2_fixed1_arr);

/* Fixed deco01v2 tablet report descriptor, interface 2 (param) */
__u8 uclogic_rdesc_deco01v2_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x09,         /*      Report Count (9),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_deco01v2_fixed2_size =
			sizeof(uclogic_rdesc_deco01v2_fixed2_arr);

/* Fixed deco02 tablet report descriptor, interface 0 (mouse) */
__u8 uclogic_rdesc_deco02_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x09,         /*      Report ID (9),                  */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x03,         /*          Usage Maximum (03h),        */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x95, 0x03,         /*          Report Count (3),           */
0x75, 0x01,         /*          Report Size (1),            */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0x05, 0x0D,         /*          Usage Page (Digitizer),     */
0x09, 0x30,         /*          Usage (Tip Pressure),       */
0x26, 0xFF, 0x1F,   /*          Logical Maximum (8191),     */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0xC0                /*      End Collection,                 */

};

const size_t uclogic_rdesc_deco02_fixed0_size =
			sizeof(uclogic_rdesc_deco02_fixed0_arr);

/* Fixed deco02 tablet report descriptor, interface 1 (pen and keyboard) */
__u8 uclogic_rdesc_deco02_fixed1_arr[] = {
0x05, 0x0D,         /*  Usage Page (Digitizer),             */
0x09, 0x02,         /*  Usage (Pen),                        */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x07,         /*      Report ID (7),                  */
0x09, 0x20,         /*      Usage (Stylus),                 */
0xA1, 0x00,         /*      Collection (Physical),          */
0x09, 0x42,         /*          Usage (Tip Switch),         */
0x09, 0x44,         /*          Usage (Barrel Switch),      */
0x09, 0x46,         /*          Usage (Tablet Pick),        */
0x09, 0x3C,         /*          Usage (Invert),             */
0x09, 0x32,         /*          Usage (In Range),           */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x75, 0x01,         /*          Report Size (1),            */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x03,         /*          Report Count (3),           */
0x81, 0x03,         /*          Input (Constant, Variable), */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x26, 0x50, 0x57,   /*          Logical Maximum (22352),    */
0x55, 0x0D,         /*          Unit Exponent (13),         */
0x65, 0x13,         /*          Unit (Inch),                */
0x35, 0x00,         /*          Physical Minimum (0),       */
0x46, 0x50, 0x57,   /*          Physical Maximum (22352),   */
0x75, 0x10,         /*          Report Size (16),           */
0x95, 0x01,         /*          Report Count (1),           */
0x81, 0x02,         /*          Input (Variable),           */
0x09, 0x31,         /*          Usage (Y),                  */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x26, 0x92, 0x36,   /*          Logical Maximum (13970),    */
0x55, 0x0D,         /*          Unit Exponent (13),         */
0x65, 0x13,         /*          Unit (Inch),                */
0x35, 0x00,         /*          Physical Minimum (0),       */
0x46, 0x92, 0x36,   /*          Physical Maximum (13970),   */
0x75, 0x10,         /*          Report Size (16),           */
0x95, 0x01,         /*          Report Count (1),           */
0x81, 0x02,         /*          Input (Variable),           */
0x05, 0x0D,         /*          Usage Page (Digitizer),     */
0x09, 0x30,         /*          Usage (Tip Pressure),       */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x26, 0xFF, 0x1F,   /*          Logical Maximum (8191),     */
0x75, 0x10,         /*          Report Size (16),           */
0x95, 0x01,         /*          Report Count (1),           */
0x81, 0x02,         /*          Input (Variable),           */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x06,         /*  Usage (Keyboard),                   */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x03,         /*      Report ID (3),                  */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0xE0,         /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,         /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,         /*      Logical Minimum (0),            */
0x25, 0x01,         /*      Logical Maximum (1),            */
0x75, 0x01,         /*      Report Size (1),                */
0x95, 0x08,         /*      Report Count (8),               */
0x81, 0x02,         /*      Input (Variable),               */
0x05, 0x07,         /*      Usage Page (Keyboard),          */
0x19, 0x00,         /*      Usage Minimum (None),           */
0x29, 0xFF,         /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),          */
0x75, 0x08,         /*      Report Size (8),                */
0x95, 0x06,         /*      Report Count (6),               */
0x81, 0x00,         /*      Input,                          */
0xC0                /*  End Collection                      */
};

const size_t uclogic_rdesc_deco02_fixed1_size =
			sizeof(uclogic_rdesc_deco02_fixed1_arr);



/* Fixed deco02 tablet report descriptor, interface 2 (param) */
__u8 uclogic_rdesc_deco02_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x09,         /*      Report Count (9),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_deco02_fixed2_size =
			sizeof(uclogic_rdesc_deco02_fixed2_arr);


/* Fixed deco03 tablet report descriptor, interface 0 (mouse) */
__u8 uclogic_rdesc_deco03_fixed0_arr[] = {
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x02,         /*  Usage (Mouse),                      */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x09,         /*      Report ID (9),                  */
0x09, 0x01,         /*      Usage (Pointer),                */
0xA1, 0x00,         /*      Collection (Physical),          */
0x05, 0x09,         /*          Usage Page (Button),        */
0x19, 0x01,         /*          Usage Minimum (01h),        */
0x29, 0x03,         /*          Usage Maximum (03h),        */
0x15, 0x00,         /*          Logical Minimum (0),        */
0x25, 0x01,         /*          Logical Maximum (1),        */
0x95, 0x03,         /*          Report Count (3),           */
0x75, 0x01,         /*          Report Size (1),            */
0x81, 0x02,         /*          Input (Variable),           */
0x95, 0x05,         /*          Report Count (5),           */
0x81, 0x01,         /*          Input (Constant),           */
0x05, 0x01,         /*          Usage Page (Desktop),       */
0x09, 0x30,         /*          Usage (X),                  */
0x09, 0x31,         /*          Usage (Y),                  */
0x26, 0xFF, 0x7F,   /*          Logical Maximum (32767),    */
0x95, 0x02,         /*          Report Count (2),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0x05, 0x0D,         /*          Usage Page (Digitizer),     */
0x09, 0x30,         /*          Usage (Tip Pressure),       */
0x26, 0xFF, 0x1F,   /*          Logical Maximum (8191),     */
0x95, 0x01,         /*          Report Count (1),           */
0x75, 0x10,         /*          Report Size (16),           */
0x81, 0x02,         /*          Input (Variable),           */
0xC0,               /*      End Collection,                 */
0xC0,               /*  End Collection,                     */
0x05, 0x01,         /*  Usage Page (Desktop),               */
0x09, 0x00,         /*  Usage (00h),                        */
0xA1, 0x01,         /*  Collection (Application),           */
0x85, 0x04,         /*      Report ID (4),                  */
0xA1, 0x00,         /*      Collection (Physical),          */
0x26, 0xFF, 0x00,   /*          Logical Maximum (255),      */
0x09, 0x00,         /*          Usage (00h),                */
0x75, 0x08,         /*          Report Size (8),            */
0x95, 0x07,         /*          Report Count (7),           */
0xB1, 0x02,         /*          Feature (Variable),         */
0xC0,               /*      End Collection,                 */
0xC0                /*  End Collection                      */

};

const size_t uclogic_rdesc_deco03_fixed0_size =
			sizeof(uclogic_rdesc_deco03_fixed0_arr);

/* Fixed deco03 tablet report descriptor, interface 1 (pen and keyboard) */
__u8 uclogic_rdesc_deco03_fixed1_arr[] = {
0x05, 0x0D,                     /*  Usage Page (Digitizer),             */
0x09, 0x01,                     /*  Usage (Digitizer),                  */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x07,                     /*      Report ID (7),                  */
0x09, 0x20,                     /*      Usage (Stylus),                 */
0xA1, 0x00,                     /*      Collection (Physical),          */
0x09, 0x42,                     /*          Usage (Tip Switch),         */
0x09, 0x44,                     /*          Usage (Barrel Switch),      */
0x09, 0x46,                     /*          Usage (Tablet Pick),        */
0x15, 0x00,                     /*          Logical Minimum (0),        */
0x25, 0x01,                     /*          Logical Maximum (1),        */
0x75, 0x01,                     /*          Report Size (1),            */
0x95, 0x03,                     /*          Report Count (3),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x09, 0x32,                     /*          Usage (In Range),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x81, 0x02,                     /*          Input (Variable),           */
0x95, 0x02,                     /*          Report Count (2),           */
0x81, 0x03,                     /*          Input (Constant, Variable), */
0x75, 0x10,                     /*          Report Size (16),           */
0x95, 0x01,                     /*          Report Count (1),           */
0x35, 0x00,                     /*          Physical Minimum (0),       */
0xA4,                           /*          Push,                       */
0x05, 0x01,                     /*          Usage Page (Desktop),       */
0x09, 0x30,                     /*          Usage (X),                  */
0x65, 0x13,                     /*          Unit (Inch),                */
0x55, 0x0D,                     /*          Unit Exponent (13),         */
0x46, 0x34, 0x03,               /*          Physical Maximum (820),     */
0x27, 0x70, 0xC6, 0x00, 0x00,   /*          Logical Maximum (50800),    */
0x81, 0x02,                     /*          Input (Variable),           */
0x09, 0x31,                     /*          Usage (Y),                  */
0x46, 0x4D, 0x04,               /*          Physical Maximum (1101),    */
0x27, 0x9F, 0x6F, 0x00, 0x00,   /*          Logical Maximum (28575),    */
0x81, 0x02,                     /*          Input (Variable),           */
0xB4,                           /*          Pop,                        */
0x09, 0x30,                     /*          Usage (Tip Pressure),       */
0x45, 0x00,                     /*          Physical Maximum (0),       */
0x26, 0xFF, 0x1F,               /*          Logical Maximum (8191),     */
0x81, 0x02,                     /*          Input (Variable),           */
0xC0,                           /*      End Collection,                 */
0xC0,                           /*  End Collection,                     */
0x05, 0x01,                     /*  Usage Page (Desktop),               */
0x09, 0x06,                     /*  Usage (Keyboard),                   */
0xA1, 0x01,                     /*  Collection (Application),           */
0x85, 0x03,                     /*      Report ID (3),                  */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0xE0,                     /*      Usage Minimum (KB Leftcontrol), */
0x29, 0xE7,                     /*      Usage Maximum (KB Right GUI),   */
0x15, 0x00,                     /*      Logical Minimum (0),            */
0x25, 0x01,                     /*      Logical Maximum (1),            */
0x75, 0x01,                     /*      Report Size (1),                */
0x95, 0x08,                     /*      Report Count (8),               */
0x81, 0x02,                     /*      Input (Variable),               */
0x05, 0x07,                     /*      Usage Page (Keyboard),          */
0x19, 0x00,                     /*      Usage Minimum (None),           */
0x29, 0xFF,                     /*      Usage Maximum (FFh),            */
0x26, 0xFF, 0x00,               /*      Logical Maximum (255),          */
0x75, 0x08,                     /*      Report Size (8),                */
0x95, 0x06,                     /*      Report Count (6),               */
0x81, 0x00,                     /*      Input,                          */
0xC0                            /*  End Collection                      */
};

const size_t uclogic_rdesc_deco03_fixed1_size =
			sizeof(uclogic_rdesc_deco03_fixed1_arr);



/* Fixed deco03 tablet report descriptor, interface 2 (param) */
__u8 uclogic_rdesc_deco03_fixed2_arr[] = {
0x06, 0x0A, 0xFF,   /*  Usage Page (FF0Ah),         */
0x09, 0x01,         /*  Usage (01h),                */
0xA1, 0x01,         /*  Collection (Application),   */
0x85, 0x02,         /*      Report ID (2),          */
0x09, 0x02,         /*      Usage (02h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x81, 0x02,         /*      Input (Variable),       */
0x09, 0x03,         /*      Usage (03h),            */
0x75, 0x08,         /*      Report Size (8),        */
0x95, 0x07,         /*      Report Count (7),       */
0x15, 0x00,         /*      Logical Minimum (0),    */
0x26, 0xFF, 0x00,   /*      Logical Maximum (255),  */
0x91, 0x02,         /*      Output (Variable),      */
0xC0                /*  End Collection              */
};

const size_t uclogic_rdesc_deco03_fixed2_size =
			sizeof(uclogic_rdesc_deco03_fixed2_arr);


			
							
			

/**
 * uclogic_rdesc_template_apply() - apply report descriptor parameters to a
 * report descriptor template, creating a report descriptor. Copies the
 * template over to the new report descriptor and replaces every occurrence of
 * UCLOGIC_RDESC_PH_HEAD, followed by an index byte, with the value from the
 * parameter list at that index.
 *
 * @template_ptr:	Pointer to the template buffer.
 * @template_size:	Size of the template buffer.
 * @param_list:		List of template parameters.
 * @param_num:		Number of parameters in the list.
 *
 * Returns:
 *	Kmalloc-allocated pointer to the created report descriptor,
 *	or NULL if allocation failed.
 */
__u8 *uclogic_rdesc_template_apply(const __u8 *template_ptr,
				   size_t template_size,
				   const s32 *param_list,
				   size_t param_num)
{
	static const __u8 head[] = {UCLOGIC_RDESC_PH_HEAD};
	__u8 *rdesc_ptr;
	__u8 *p;
	s32 v;

	rdesc_ptr = kmemdup(template_ptr, template_size, GFP_KERNEL);
	if (rdesc_ptr == NULL)
		return NULL;

	for (p = rdesc_ptr; p + sizeof(head) < rdesc_ptr + template_size;) {
		if (memcmp(p, head, sizeof(head)) == 0 &&
		    p[sizeof(head)] < param_num) {
			v = param_list[p[sizeof(head)]];
			put_unaligned(cpu_to_le32(v), (s32 *)p);
			p += sizeof(head) + 1;
		} else {
			p++;
		}
	}

	return rdesc_ptr;
}
