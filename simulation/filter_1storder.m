#!/bin/octave
%frequency magnitude response of 1st order LC LPF with 50ohm input/output loading

%% sage code used to produce transfer function
## va,vo,vi,s,L,C = var('va,vo,vi,s,L,C')
## eq1 = vo/50 + (vo-va)/(s*L) == 0
## eq2 = (va - vo)/(s*L) + s*C*va + (va - vi)/50 == 0
## solve([eq1,eq2],vo,va)

function out = bode(w)
  C = 6.5e-12;
  L = 18e-9;

  s = i*w;
  out = 50./((50*C*s.^2 + s)*L + 2500*C*s + 100);
endfunction

f = linspace(0,900e6,200);
w = 2*pi*f;

hold on
plot(f,abs(bode(w)))
plot(433e6,abs(bode(2*pi*433e6)),'ro')
plot(866e6,abs(bode(2*pi*866e6)),'ro')
xlabel('Frequency Hz')
ylabel('Gain')

pause
