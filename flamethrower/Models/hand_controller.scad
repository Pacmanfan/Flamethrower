/*
This is a basic design for a hand-held controller grip
for the flamethrower gauntlet

This is held horizontally

I should make this so that it works ambidextrously
*/
cont_height = 90; // controller height
cont_height_trim = 88; // controller height trimmed
cont_diam = 25.4; // 1 inch diam
rounding = 123;
module hand_controller_base()
{
    difference()
    {
        union()
        {
            cylinder(h=cont_height,r = cont_diam /2 , $fn = rounding);
            //add balls on the end
            translate([0,0,cont_height])
                sphere(r = cont_diam /2 , $fn = rounding);

            sphere(r = cont_diam /2 , $fn = rounding);
        }
    // this large flat cylinder is used to take away the paddle section    
    translate([0,0,cont_height/2])
        rotate([90,0,0])
            cylinder(h = cont_diam, r = cont_height/2, $fn =rounding);        
        
    //take away area for thumb
    translate([-50,0,cont_height + 32])
        rotate([0,90,0])
            cylinder(h=cont_height,r = cont_diam  , $fn = rounding);
    }
}

module paddle()
{
    intersection()
    {
        cylinder(h = cont_diam/2, r = cont_height_trim/2, $fn =rounding);    
        translate([0,0,cont_diam/4])
        cube([cont_diam,cont_height_trim,cont_diam,],true);
        translate([0,cont_height_trim/2,-cont_height_trim/2 + cont_diam/2])
            rotate([90,0,0])
                cylinder(h = cont_height_trim, r = cont_height_trim/2, $fn =rounding);
    }
}

hand_controller_base();
translate([0,0,cont_height/2])
rotate([90,0,0])
paddle();