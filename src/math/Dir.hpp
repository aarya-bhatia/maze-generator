#pragma once

namespace Math
{
   namespace Dir
   {
      enum dir_t
      {
         top = 1,
         right,
         bottom,
         left
      };

      ///
      // @return check whether the direction is in the Y direction i.e top or bottom.
      ///
      bool isY(dir_t dir)
      {
         return (dir & 1) != 0;
      }

      ///
      // @return check whether the direction is in the X direction i.e right or left.
      ///
      bool isX(int dir)
      {
         return (dir & 1) == 0;
      }

      ///
      // @return returns the inverse of dir, eg: top -> bottom, right -> left
      ///
      int inverse(int dir)
      {
         return 1 + ((dir + 1) & 3);
      };
   }
}