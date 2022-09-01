using com.knapp.CodingContest.warehouse;
using com.knapp.CodingContest.data;
using System.Collections.Generic;
using com.knapp.CodingContest.core;
using System.Linq;
using System;

namespace com.knapp.CodingContest.solution
{
    public class Solution
    {

        public string ParticipantName { get; protected set; }

        public Institutes Institute { get; protected set; }

        protected readonly InputData input;
        protected readonly IWarehouse warehouse;

        protected readonly Storage storage;
        protected readonly Location entryLocation;
        protected readonly Location exitLocation;
        protected readonly Robot robot;

        public Solution( IWarehouse warehouse, InputData input )
        {
            this.warehouse = warehouse;
            this.input = input;

            storage = warehouse.GetStorage();
            entryLocation = storage.EntryLocation;
            exitLocation = storage.ExitLocation;
            robot = storage.Robot;

            ParticipantName = "Gabriel";
            Institute = Institutes.Sonstige;

            //TODO: Prepare data structures
        }
        private Location GetLocById(string code)
        {
            for (int j = 0; j < 999; j++)
            {
                for (int i = 0; i < 14; i++)
                {
                    Location loc = storage.GetLocation(i, j);
                    List<Product> locList = loc.GetCurrentProducts().ToList();
                    foreach (var item in locList)
                    {
                        if (item.Code == code)
                        {
                            return loc;
                        }
                    }
                }
            }
            return null;
        }
        private void Load()
        {
            int lw = 0;
            while (warehouse.GetRemainingProductsAtEntry().Count != 0)
            {
                    Product aktProduct = warehouse.GetRemainingProductsAtEntry().ElementAt(0);
                if (aktProduct.Length <= robot.GetRemainingLength() && aktProduct.Width >= lw)
                {
                    robot.PullFrom(entryLocation);
                    lw = aktProduct.Width;
                }
                else
                {
                    break;
                }
            }
        }
        private void UnloadToStorage()
        { 
            while (robot.GetCurrentProducts().Count != 0)
            {
                
                Location loc = getFreeLocation();
                robot.PushTo(loc);
            }
        }
        public bool isSpaceLeft(Location location, Product product)
        {
            int remainingLength = location.GetRemainingLength();
            int productLength = product.Length;
            if (productLength <= remainingLength)
            {
                return true;
            }
            return false;
        }
        public Location getFreeLocation()
        {
            Location emptyLocation = null;
            for (int pos = 0; pos < 999; pos++)
            {
                for (int lvl = 0; lvl < 14; lvl++)
                {
                    Location loc = storage.GetLocation(lvl, pos);
                    if (loc.GetCurrentProducts().Count != 0)
                    {
                        Product locProd = loc.GetCurrentProducts().ElementAt(0);
                        Product robProd = robot.GetCurrentProducts().ElementAt(0);
                        if (locProd.Code == robProd.Code)
                        {
                            if (isSpaceLeft(loc, robProd))
                            {
                                return loc;
                            }
                        }
                    }
                    else if (emptyLocation == null)
                    {
                        emptyLocation = loc;
                    }
                }
            }
            return emptyLocation;
        }
        private void CheckIfProductIsInOrder(Order order)
        {
            List<Product> lp = robot.GetCurrentProducts().ToList();
            Product p = lp[0];
            if (order.GetProducts().Contains(p))
            {
                robot.PushTo(exitLocation);
            }
            else
            {
                return;
            }
        }
        private void MoveFromEntryToStorage()
        {
            for (int j = 0; j < 999; j++)
            {
                for (int i = 0; i < 14; i++)
                {
                    if (entryLocation.GetCurrentProducts().Count == 0)
                    {
                        break;
                    }
                    Load();
                    UnloadToStorage();
                }
            }
        }
        private void MoveFromStorageToExit()
        {
            while (true)
            {
                
                List<Product> plist = order.GetProducts();
                List<Product> sorted = plist.OrderBy(p => p.Code).OrderBy(p => p.Width).ToList();
                while (sorted.Count() != 0)
                {
                    int len = sorted.ElementAt(0).Length;
                    string code = sorted.ElementAt(0).Code;
                    if (len < robot.GetRemainingLength())
                    {
                        Location loc = GetLocById(code);             
                        robot.PullFrom(loc);
                        sorted.Remove(sorted.ElementAt(0));
                    }
                    else
                    {
                        while (robot.GetCurrentProducts().Count != 0)
                        {   
                            robot.PushTo(exitLocation);
                        }
                    }
                }
                while (robot.GetCurrentProducts().Count != 0)
                {
                    robot.PushTo(exitLocation);
                }
            }
        }
        public virtual void Run()
        {
           
            try
            {
                MoveFromEntryToStorage();
                MoveFromStorageToExit();
            } catch (NoMoreOrdersException e) {
                Console.WriteLine("Fehler: " +e);
            }
        }
        /// <summary>
        /// Just for documentation purposes.
        ///
        /// Method may be removed without any side-effects
        ///
        /// divided into 4 sections
        ///
        ///     <li><em>input methods</em>
        ///
        ///     <li><em>main interaction methods</em>
        ///         - these methods are the ones that make (explicit) changes to the warehouse
        ///
        ///     <li><em>information</em>
        ///         - information you might need for your solution
        ///
        ///     <li><em>additional information</em>
        ///         - various other infos: statistics, information about (current) costs, ...
        ///
        /// </summary>
#pragma warning disable IDE0051 // Nicht verwendete private Member entfernen
        private void Apis()
#pragma warning restore IDE0051 // Nicht verwendete private Member entfernen
        {
            // ----- input -----

            IReadOnlyList<Product> allProductsAtEntry = input.GetAllProductsAtEntry();

            IReadOnlyList<Order> allOrders = input.GetAllOrders();

            IReadOnlyCollection<Product> remainingProducts = warehouse.GetRemainingProductsAtEntry();

            IReadOnlyCollection<Order> remainingOrders = warehouse.GetRemainingOrders();

            Location location0 = storage.GetLocation(0, 0);
            List<Location> allLocations = storage.GetAllLocations();

            // ----- main interaction methods -----


            Location location;
            location = entryLocation;
            robot.PullFrom(location);

            location = exitLocation;
            robot.PushTo(location);

            Order order = warehouse.NextOrder();

            // ----- information -----

            Product product = order.GetProducts()[0];

            location.GetType();
            int level = location.Level;
            int position = location.Position;
            int length = location.Length;
            location.GetCurrentProducts();

            Location lamLocation = robot.CurrentLocation;
            robot.GetCurrentProducts();
            int robotLength = robot.Length;
            robot.GetRemainingLength();
            robot.GetCurrentMaxWidth();

            // ----- additional information -----
            IWarehouseInfo whi = warehouse.GetInfoSnapshot();
        }
    }
}
