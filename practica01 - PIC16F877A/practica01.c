/// Librer�a del pic con .h
#include <16f877a.h>

/// Configuraci�n del adc a resulci�n de 10bits         
#device adc=10  

/// Se configurar el valor del delay con el del clock
#use delay(clock=4000000)

/// Desactivaci�n de fuses o activaci�n 
#fuses XT,NOWDT,NOPROTECT,NOLVP,PUT

/// Se configuran los grupos de pines RA,RC para entrada/salida
#use fast_io(a)
#use fast_io(c)

/// Variable enteera para las lecturas
float lectura;

void main()
{
	/// Configura los puertos como entrada o salida
	set_tris_a(1);
	set_tris_c(0);
	
	/// Se configura el reloj interno que trabaja todo el tiempo
	setup_adc(ADC_CLOCK_INTERNAL);

	/// Se configuran los pines con AN# para entradas anaogas
	setup_adc_ports(ALL_ANALOG);

	/// Se configura el canal de entrada AN0
	set_adc_channel(0);

	while(true)
	{
		/// Se configura el canal de entrada AN0
		set_adc_channel(0);

		///Retardo de 10 milisegundos
		delay_ms(10);

		/// int read se llena con lo que lee en el adc
		lectura = read_adc();
		
		///Retardo
		delay_ms(10);
		
		/// Condicional para activar los LED's
		if(lectura > 300)
		{
			output_high(PIN_C0);
		}
		else
		{
			output_low(PIN_C0);
		}
		
		/// Configuraci�n del el canal de entrada AN1
		set_adc_channel(1);
		delay_ms(10);
		lectura = read_adc();
		delay_ms(10);
		
		/// Condicional para activar los LED's
		if(lectura > 300)
		{
			output_high(PIN_C1);
		}
		else
		{
			output_low(PIN_C1);
		}
		
		/// Se reconfigura el canal
		set_adc_channel(0);
		delay_ms(10);	
	}
}