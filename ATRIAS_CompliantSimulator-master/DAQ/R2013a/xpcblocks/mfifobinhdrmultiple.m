function [maskdisplay, hdr, hlengths] = mfifobinhdrmultiple( header, lengths )
% mfifobinhdrmultiple -- mask initialization file for the BINARY FIFO multi
% header multiple read block for xPC Target
  
% Copyright 1996-2007 The MathWorks, Inc.
% $Revision: 1.1.8.5 $ $Date: 2011/09/19 18:03:52 $

  maskdisplay= 'disp( ''FIFO Read\nBINARY MULTIPLE'');';
  maskdisplay=[maskdisplay,'port_label(''input'',1,''F'');'];
  enable = get_param( gcb, 'enable' );
  if strcmp( enable, 'on' )
    maskdisplay=[maskdisplay,'port_label(''input'',2,''E'');'];
  end
  
  if iscell( header )
    nhdrs = length(header);
    mx = 0;
    for nh = 1:nhdrs
      mx = max( mx, length(header{nh}) );
    end
  
    hdr = zeros( nhdrs, mx );
  
    for nh = 1:nhdrs
      st = header{nh};
      lh = length(header{nh});
      for ch = 1:lh
        hdr(nh,ch) = st(ch);
      end
    end
    % compute the significant length of each header
    hlengths = zeros(1,nhdrs);
    for cnt = 1:nhdrs
      hlengths(1,cnt) = length(header{cnt});
    end
  else
    hdr = double(header);
    nhdrs = 1;
    hlengths = length(header);
  end

  for n = 1:nhdrs
    maskdisplay = [maskdisplay, 'port_label(''output'',',num2str(n),',''',num2str(n),''');']; %#ok
  end
  
  nlengths = length(lengths);
  if nlengths ~= nhdrs
    error(message('xPCTarget:ReadFIFO:Config'));
  end
