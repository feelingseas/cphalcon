<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Query\Status;

use IntegrationTester;

class GetMessagesCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Status :: getMessages()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelQueryStatusGetMessages(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Query\Status - getMessages()");
        $I->skipTest("Need implementation");
    }
}
