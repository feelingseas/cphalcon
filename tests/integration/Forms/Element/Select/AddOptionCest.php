<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Element\Select;

use IntegrationTester;

/**
 * Class AddOptionCest
 */
class AddOptionCest
{
    /**
     * Tests Phalcon\Forms\Element\Select :: addOption()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementSelectAddOption(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Select - addOption()');
        $I->skipTest('Need implementation');
    }
}
