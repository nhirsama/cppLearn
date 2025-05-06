d = 1;
epsilon0 = 8.85e-12;
N = 100;
r = 5;
[x, y] = meshgrid(linspace(-r, r, N), linspace(-r, r, N));
Ex = zeros(size(x));
Ey = zeros(size(y));
for i = 1:N
    for j = 1:N
        xp = x(i,j);
        yp = y(i,j);
        r1 = sqrt(xp^2 + yp^2);

        if r1 ~= 0
            Ex(i,j) = 3*d*xp / (4*pi*epsilon0 * (r1^5));
            Ey(i,j) = 3*d*yp / (4*pi*epsilon0 * (r1^5));
        end
    end
end
E = sqrt(Ex.^2 + Ey.^2);
figure;
quiver(x, y, Ex, Ey, 'AutoScaleFactor', 1.5);
axis equal;
title('电偶极子的电场分布');
xlabel('x (m)');
ylabel('y (m)');
