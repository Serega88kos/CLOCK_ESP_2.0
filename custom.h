#pragma once
#include "GyverPortal.h"

void MY_JQ_CLOCK() {
  GP.SEND("<script>$(document).ready(function(){");
  GP.SEND("$('#add').click(function(){");
  GP.SEND("$('#orderDisplay').val($('#orderDisplay').val()+$('#mode').val()+',');");
  GP.SEND("$('#periodDisplay').val($('#periodDisplay').val()+$('#time').val()+',');});");
  GP.SEND("$('#del').click(function(){$('#orderDisplay').val('');");
  GP.SEND("$('#periodDisplay').val('');});});</script>");
}

void MY_JQ_MON() {
  GP.SEND("<script>$(document).ready(function(){$('#Monitoring').click(function(){");
  GP.SEND("if ($(this).is(':checked')){");
  GP.SEND("$('.blockBase').eq(2).show(100);");
  GP.SEND("$('.blockBase').eq(3).show(100);");
  GP.SEND("} else {");
  GP.SEND("$('.blockBase').eq(2).hide(100);");
  GP.SEND("$('.blockBase').eq(3).hide(100);}});");
  GP.SEND("if($('#Monitoring').is(':checked')) {");
  GP.SEND("$('.blockBase').eq(2).show(100);");
  GP.SEND("$('.blockBase').eq(3).show(100);}");
  GP.SEND("else{");
  GP.SEND("$('.blockBase').eq(2).hide(100);");
  GP.SEND("$('.blockBase').eq(3).hide(100);}");  
  GP.SEND("});</script>");
}

void MY_JQ_DFP() {
  GP.SEND("<script>$(document).ready(function(){$('#status_kuku').click(function(){");
  GP.SEND("if ($(this).is(':checked')){");
  GP.SEND("$('.blockBase').eq(1).show(100);");
  GP.SEND("$('.blockBase').eq(2).show(100);");
  GP.SEND("$('.blockBase').eq(3).show(100);");
  GP.SEND("$('.blockBase').eq(4).show(100);");
  GP.SEND("} else {");
  GP.SEND("$('.blockBase').eq(1).hide(100);");
  GP.SEND("$('.blockBase').eq(2).hide(100);");
  GP.SEND("$('.blockBase').eq(3).hide(100);");
  GP.SEND("$('.blockBase').eq(4).hide(100);}});");
  GP.SEND("if($('#status_kuku').is(':checked')) {");
  GP.SEND("$('.blockBase').eq(1).show(100);");
  GP.SEND("$('.blockBase').eq(2).show(100);");
  GP.SEND("$('.blockBase').eq(3).show(100);");
  GP.SEND("$('.blockBase').eq(4).show(100);}");
  GP.SEND("else{");
  GP.SEND("$('.blockBase').eq(1).hide(100);");
  GP.SEND("$('.blockBase').eq(2).hide(100);");
  GP.SEND("$('.blockBase').eq(3).hide(100);");
  GP.SEND("$('.blockBase').eq(4).hide(100);}");  
  GP.SEND("});</script>");
}

void MY_BLOCK1() {
  GP.SEND("<select id='mode' name='mode'>");
  GP.SEND("<option value='0'>0.Часы</option>");
  GP.SEND("<option value='1'>1.Темп. дома</option>");
  GP.SEND("<option value='2'>2.Темп. улица</option>");
  GP.SEND("<option value='3'>3.Давление</option>");
  GP.SEND("<option value='4'>4.Влажность</option>");
  GP.SEND("<option value='5'>5.Дата</option></select>");
}

void MY_BLOCK2() {
  GP.SEND("<input type='number' id='time' min='2' value='2' max='60'/>");
}

void MY_BLOCK3() {
  GP.BUTTON_MINI("add", "+", "add", colorTheme);
}

void MY_BLOCK4() {
  GP.BUTTON_MINI("del", "x", "del", colorTheme);
}