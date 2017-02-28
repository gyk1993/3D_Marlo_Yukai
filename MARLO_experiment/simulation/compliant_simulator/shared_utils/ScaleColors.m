function [IMG,sc] = ScaleColors(IMG,sc)
    
    if nargin<2
        figure;
        h = imshow(IMG);
        pt = impoint();
        addNewPositionCallback(pt, @(pos)redraw(h,IMG,pos));
        redraw(h,IMG,pt.getPosition())
        
        % Wait for double-click
        pos = round(wait(pt));
        delete(pt);
        sc  = reshape(IMG(pos(2), pos(1), :), 1, 3);
        fprintf('Color Scaling:\n %s\n', mat2str(sc));
    end
    
    IMG = scale(IMG, sc);
    
end

function redraw(h,IMG,pos)
    pos = round(pos);
    sc  = reshape(IMG(pos(2), pos(1), :), 1, 3);
    set(h, 'CData', scale(IMG, sc));
    drawnow;
end

function IMG = scale(IMG, sc)
    I = double(IMG);
    sc = double(sc);
    I(:,:,1) = I(:,:,1)/(sc(1)/255);
    I(:,:,2) = I(:,:,2)/(sc(2)/255);
    I(:,:,3) = I(:,:,3)/(sc(3)/255);
    I = max(0, min(I, 255));
    IMG = uint8(I);
end
