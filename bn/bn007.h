//
// Created by chao li on 9/7/16.
//

#ifndef LIBCPPBN_BN007_H
#define LIBCPPBN_BN007_H

#include <iostream>
#include <string>

using namespace std;

/// only for testing PC works
class bn007 {

public:
    /// 构造函数
    ///
    /// The distance between \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.
    ///
    /// \f[
    /// |I_2|=\left| \int_{0}^T \psi(t)
    /// \left\{
    ///    u(a,t)-
    ///    \int_{\gamma(t)}^a
    ///     \frac{d\theta}{k(\theta,t)}
    ///    \int_{a}^\theta c(\xi)u_t(\xi,t)\,d\xi
    ///    \right\} dt
    /// \right|
    ///  \f]
    ///
    /// The distance between \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.

    /// \return

    bn007(){
        std::cout << "new an empty bn007 object." << std::endl;
    }


    ~bn007(){
        std::cout << "delete an empty bn007 object." << std::endl;
    }

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */

    void talk(){
        std::cout << "talk: 我是007!" << std::endl;
    }

    //! 说一个string函数
    //! \param x
    void tell(const std::string& x);

private:
    int var1;//!< Brief description after the member
    int var2;
    int var; /*!< Detailed description after the member */


};


#endif //LIBCPPBN_BN007_H
